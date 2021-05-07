import Foundation

var top = 0
var c: Character
var stack: [Character] = []

let inputValues = readLine()!.split(separator: " ").map { Int($0)! }
var n: Int = inputValues[0]
var k: Int = inputValues[1]
var numbers: [Character] = Array(readLine()!)

for i in 0...n-1 {
    while k > 0 && !stack.isEmpty && stack.last! < numbers[i] {
        stack.popLast()
        k -= 1
    }
    stack.append(numbers[i])
}

for i in 0...(stack.count - k - 1) {
    print(stack[i], terminator: "")
}
