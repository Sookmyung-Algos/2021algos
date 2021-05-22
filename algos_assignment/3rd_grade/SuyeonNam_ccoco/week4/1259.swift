import Foundation

while true {
    let number: [Character] = Array(readLine()!)
    if number[0] == "0" {
        break
    }
    var is_palindrome: Bool = true

    for i in 0...(number.count / 2) {
        if number[i] != number[number.count - i - 1] {
            print("no")
            is_palindrome = false
            break
        }
    }
    if is_palindrome {
        print("yes")
    }
}
