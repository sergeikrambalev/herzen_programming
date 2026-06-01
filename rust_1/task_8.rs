#[derive(Debug, PartialEq, Copy, Clone)]
enum Position {
    Manager,
    Developer,
    Designer,
    Analytic,
}

#[derive(Clone)]
struct Employee {
    name: String,
    position: Position,
    salary: u32,
}

fn filter_by_position(employees: &[Employee], target_position: Position) -> Vec<Employee> {
    let mut result = Vec::new();
    for empl in employees {
        if empl.position == target_position {
            result.push(Employee {
                name: empl.name.clone(),
                position: empl.position.clone(),
                salary: empl.salary,
            });
        }
    }
    result
}

fn main() {
    let staff = vec![
        Employee {
            name: "Serj".to_string(),
            position: Position::Developer,
            salary: 110000,
        },
        Employee {
            name: "Dan".to_string(),
            position: Position::Developer,
            salary: 100000,
        },
        Employee {
            name: "Alan".to_string(),
            position: Position::Manager,
            salary: 215000,
        },
        Employee {
            name: "Bob".to_string(),
            position: Position::Analytic,
            salary: 140000,
        },
        Employee {
            name: "Shindel".to_string(),
            position: Position::Designer,
            salary: 90000,
        },
    ];

    let developers = filter_by_position(&staff, Position::Developer);

    println!("Developers:");
    for dev in developers {
        println!("{} ({}g)", dev.name, dev.salary);
    }
}
