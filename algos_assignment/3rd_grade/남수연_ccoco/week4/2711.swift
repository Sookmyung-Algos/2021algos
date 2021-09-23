import Foundation

var n: Int = Int(readLine()!)!

for _ in 1...n {
    let inputValues = readLine()!.split(separator: " ").map { String($0) }
    let ota: Int = Int(inputValues[0])! - 1
    var str: String = inputValues[1]
    
    str.remove(at: str.index(str.startIndex, offsetBy: ota))
    print(str)
}
