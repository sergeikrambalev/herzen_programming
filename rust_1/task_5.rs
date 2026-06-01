use std::io;

fn main() {
    println!("Select N: ");

    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Error reading string");

    let n: u32 = input.trim().parse().expect("Input positive integer");

    let result = fibonacci(n);
    println!("{} fibonacci number is {}", n, result);
}

fn fibonacci(n: u32) -> u64 {
    match n {
        0 => 0,
        1 => 1,
        _ => fibonacci(n - 1) + fibonacci(n - 2),
    }
}
