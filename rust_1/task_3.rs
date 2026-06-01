fn strlen(s: &str) -> usize {
    s.chars().count()
}

fn main() {
    let s1 = "Hello world";
    let s2 = "";
    let s3 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Cras porta";

    println!("Length of '{}' = {}", s1, strlen(s1));
    println!("Length of '{}' = {}", s2, strlen(s2));
    println!("Length of '{}' = {}", s3, strlen(s3));
}
