#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct Vector3 {
  char name[10];
  double x, y, z;
} Vector3;

Vector3 create_vector(const char *name, double x, double y, double z) {
  Vector3 vec;
  strcpy(vec.name, name);
  vec.x = x;
  vec.y = y;
  vec.z = z;
  return vec;
}

void print_vec(Vector3 vec) {
  printf("%s = (%.2f, %.2f, %.2f)\n", vec.name, vec.x, vec.y, vec.z);
}

double dot_product(Vector3 vec1, Vector3 vec2) {
  return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}

Vector3 cross_product(Vector3 vec1, Vector3 vec2) {
  Vector3 result;
  strcpy(result.name, "cross_product");
  result.x = vec1.y * vec2.z - vec1.z * vec2.y;
  result.y = vec1.z * vec2.x - vec1.x * vec2.z;
  result.z = vec1.x * vec2.y - vec1.y * vec2.x;
  return result;
}

double vec_len(Vector3 vec) {
  return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

Vector3 vec_sum(Vector3 vec1, Vector3 vec2) {
  Vector3 result;
  sprintf(result.name, "%s+%s", vec1.name, vec2.name);
  result.x = vec1.x + vec2.x;
  result.y = vec1.y + vec2.y;
  result.z = vec1.z + vec2.z;
  return result;
}

Vector3 vec_mul(Vector3 vec, double scalar) {
  Vector3 result;
  sprintf(result.name, "%s*%.1f", vec.name, scalar);
  result.x = vec.x * scalar;
  result.y = vec.y * scalar;
  result.z = vec.z * scalar;
  return result;
}

int main() {
  Vector3 vec1 = create_vector("vec1", 1.0, 2.0, 3.0);
  Vector3 vec2 = create_vector("vec2", 2.0, -1.0, 3.0);

  print_vec(vec1);
  print_vec(vec2);

  printf("Dot product of %s and %s: %.2f\n", vec1.name, vec2.name,
         dot_product(vec1, vec2));

  Vector3 cross = cross_product(vec1, vec2);
  printf("Cross product of %s and %s: ", vec1.name, vec2.name);
  print_vec(cross);

  printf("Length of %s: %.2f\n", vec1.name, vec_len(vec1));
  printf("Length of %s: %.2f\n", vec2.name, vec_len(vec2));

  Vector3 sum = vec_sum(vec1, vec2);
  printf("Sum of %s and %s: ", vec1.name, vec2.name);
  print_vec(sum);

  Vector3 mult = vec_mul(vec1, 2.5);
  printf("%s multiplied by 2.5: ", vec1.name);
  print_vec(mult);

  return 0;
}
