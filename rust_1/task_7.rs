#[derive(Debug, PartialEq, Copy, Clone)]
enum Category {
    Electronics,
    Clothing,
    Food,
    Books,
}

struct Product {
    name: String,
    price: f64,
    category: Category,
}

impl Product {
    fn display(&self) {
        println!(
            "Product {} from {:.?}, {:.2}g",
            self.name, self.category, self.price
        );
    }
    fn total_price_by_category(products: &[Product], category: Category) -> f64 {
        let mut total = 0.0;
        for product in products {
            if product.category == category {
                total += product.price;
            }
        }
        total
    }
}

fn main() {
    let products = vec![
        Product {
            name: "Lenovo ThinkBook 16P".to_string(),
            price: 35000.0,
            category: Category::Electronics,
        },
        Product {
            name: "Shorts".to_string(),
            price: 100.0,
            category: Category::Clothing,
        },
        Product {
            name: "Pizza".to_string(),
            price: 480.0,
            category: Category::Food,
        },
        Product {
            name: "Redmi Buds 4 Lite".to_string(),
            price: 2100.0,
            category: Category::Electronics,
        },
        Product {
            name: "The C Programming".to_string(),
            price: 4200.0,
            category: Category::Books,
        },
    ];

    for product in &products {
        product.display();
    }

    let total_electronics = Product::total_price_by_category(&products, Category::Electronics);
    println!("Total electronics cost: {:.2}g", total_electronics);
}
