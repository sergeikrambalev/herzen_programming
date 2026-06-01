struct Car {
    brand: String,
    model: String,
    year: u16,
}

fn main() {
    let car1 = Car {
        brand: String::from("Toyota"),
        model: String::from("Camry"),
        year: 2020,
    };
    let car2 = Car {
        brand: String::from("Ford"),
        model: String::from("Mustang"),
        year: 1969,
    };

    println!("Car 1: {} {}, {}y", car1.brand, car1.model, car1.year);
    println!("Car 2: {} {}, {}y", car2.brand, car2.model, car2.year);
}
