import Foundation

inf: while true {
    let n: Int = Int(readLine()!)!
    if n == 0 {
        break inf // 오호라 !
    }
    var str: [(original: String, lowered: String)] = []
    for _ in 1...n {
        let tmp: String = readLine()!
        str.append((tmp, tmp.lowercased()))
    }
    let newArr = str.sorted(by: { $0.lowered < $1.lowered })
    print(newArr[0].original)
}
