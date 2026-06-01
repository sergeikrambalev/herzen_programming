use std::io;

fn main() {
    let mut name = String::new();
    println!("Input name: ");

    io::stdin()
        .read_line(&mut name)
        .expect("Failed to read string");

    let name = name.trim();
    println!("Hi, {}", name);
}
