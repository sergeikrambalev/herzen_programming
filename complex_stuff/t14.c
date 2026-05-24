#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#define delay() usleep(10000)

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <file> <destination>\n", argv[0]);
    return 1;
  }

  const char *src_path = argv[1];
  const char *dst_path = argv[2];

  FILE *f_in = fopen(src_path, "rb");
  if (!f_in) {
    fprintf(stderr, "Filed to open file '%s': %s\n", src_path, strerror(errno));
    return 1;
  }

  if (fseek(f_in, 0, SEEK_END) != 0) {
    fprintf(stderr, "Positioning failure: %s\n", strerror(errno));
    fclose(f_in);
    return 1;
  }

  long size = ftell(f_in);
  if (size < 0) {
    fprintf(stderr, "Failed to get file size: %s\n", strerror(errno));
    fclose(f_in);
    return 1;
  }
  rewind(f_in);

  FILE *f_out = fopen(dst_path, "wb");
  if (!f_out) {
    fprintf(stderr, "Failed to open file '%s': %s\n", dst_path,
            strerror(errno));
    fclose(f_in);
    return 1;
  }

  char *buffer = malloc(BUFFER_SIZE);
  if (!buffer) {
    fprintf(stderr, "Failed to allocate memory for buffer\n");
    fclose(f_in);
    fclose(f_out);
    return 1;
  }

  long bytes_copied = 0;

  if (size > 0) {
    char bar[11];
    memset(bar, '-', 10);
    bar[10] = '\0';
    printf("\rCopying %s to %s [%s] %3d%%", src_path, dst_path, bar, 0);
    fflush(stdout);
  }

  while (1) {
    size_t bytes_read = fread(buffer, 1, BUFFER_SIZE, f_in);
    if (bytes_read == 0) {
      if (feof(f_in))
        break;
      fprintf(stderr, "Error while reading file: %s\n", strerror(errno));
      free(buffer);
      fclose(f_in);
      fclose(f_out);
      return 1;
    }

    size_t bytes_write = fwrite(buffer, 1, bytes_read, f_out);
    if (bytes_write != bytes_read) {
      fprintf(stderr, "Error while writing file: %s\n", strerror(errno));
      free(buffer);
      fclose(f_in);
      fclose(f_out);
      return 1;
    }

    bytes_copied += bytes_write;

    delay();

    int percent;
    if (size == 0)
      percent = 100;
    else {
      percent = (int)((double)bytes_copied / size * 100.0);
      if (percent > 100)
        percent = 100;
    }

    int filled = percent / 10;
    char bar[11];
    memset(bar, '-', 10);
    if (filled > 0)
      memset(bar, '|', filled);
    bar[10] = '\0';

    printf("\rCopying %s to %s [%s] %3d%% \033[K", src_path, dst_path, bar,
           percent);
    fflush(stdout);
  }

  printf("\rCopying %s to %s [%s] 100%% \033[K\n", src_path, dst_path,
         "||||||||||");
  printf("Done.\n");

  free(buffer);
  fclose(f_in);
  fclose(f_out);

  return 0;
}
