#[derive(Debug, PartialEq, Copy, Clone)]
enum DayOfWeek {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday,
}

fn next_day(day: DayOfWeek) -> DayOfWeek {
    match day {
        DayOfWeek::Monday => DayOfWeek::Tuesday,
        DayOfWeek::Tuesday => DayOfWeek::Wednesday,
        DayOfWeek::Wednesday => DayOfWeek::Thursday,
        DayOfWeek::Thursday => DayOfWeek::Friday,
        DayOfWeek::Friday => DayOfWeek::Saturday,
        DayOfWeek::Saturday => DayOfWeek::Sunday,
        DayOfWeek::Sunday => DayOfWeek::Monday,
    }
}

fn main() {
    let today = DayOfWeek::Friday;
    let tomorrow = next_day(today);
    println!("After {:?} comes {:?}", today, tomorrow);

    let sunday = DayOfWeek::Sunday;
    let after_sunday = next_day(sunday);
    println!("After {:?} comes {:?}", sunday, after_sunday);
}
