let s = Array(readLine()!)
for i in s {
    let a = Int(i.asciiValue!)
    for _ in 1...[a / 100, a % 100 / 10, a % 10].reduce(0, +) {
        print(i, terminator: "")
    }
    print("")
}
