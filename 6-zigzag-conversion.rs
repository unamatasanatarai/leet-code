struct Solution;
impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        let slen: i32 = s.len() as i32;
        if slen <= num_rows || slen <= 2 || num_rows == 1 {
            return s;
        }
        let mut y: i32 = 0;
        let mut dir: i32 = 1;

        let mut arr: Vec<String> = (0..num_rows).map(|_| String::new()).collect();

        for c in s.chars() {
            arr[y as usize].push(c);
            y += dir;
            if y % (num_rows - 1) == 0 {
                dir = dir * -1;
            }
        }

        return arr.join("");
    }
}

fn main() {
    let tests = vec![
        ("AB", 1, "AB"),
        ("", 1, ""),
        ("A", 1, "A"),
        ("ABC", 1, "ABC"),
        ("ABCDEFG", 2, "ACEGBDF"),
        ("ABCDEF", 2, "ACEBDF"),
        ("ABCD", 3, "ABDC"),
        ("ABCDE", 3, "AEBDC"),
        ("ABCDEF", 3, "AEBDFC"),
        ("ABCDEFG", 3, "AEBDFCG"),
        ("ABCDEFGH", 3, "AEBDFHCG"),
        ("ABCDE", 4, "ABCED"),
        ("ABCDEF", 4, "ABFCED"),
        ("ABCDEFG", 4, "AGBFCED"),
        ("ABCDEFGH", 4, "AGBFHCED"),
        ("A", 5, "A"),
        ("AB", 5, "AB"),
        ("ABC", 5, "ABC"),
        ("ABCD", 5, "ABCD"),
        ("ABCDE", 5, "ABCDE"),
        ("ABCDEF", 5, "ABCDFE"),
        ("LEETCODEISHIRING", 3, "LCIRETOESIIGEDHN"),
        ("LEETCODEISHIRING", 4, "LDREOEIIECIHNTSG"),
        ("APPS", 2, "APPS"),
        ("APPS", 3, "APSP"),
        ("APPS", 4, "APPS"),
        ("TEST", 2, "TSET"),
        ("TEST", 3, "TETS"),
        ("ZIGZAG", 3, "ZAIZGG"),
        ("ZIGZAG", 2, "ZGAIZG"),
        ("HELLO", 3, "HOELL"),
        ("HELLO", 4, "HELOL"),
        ("WORLD", 3, "WDOLR"),
        ("WORLD", 5, "WORLD"),
        ("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"),
        ("PAYPALISHIRING", 4, "PINALSIGYAHRPI"),
        ("ABC", 2, "ACB"),
        ("ABCD", 2, "ACBD"),
        ("ABCDE", 2, "ACEBD"),
        ("ABC", 10, "ABC"),
        ("", 100, ""),
        ("X", 1, "X"),
        ("XY", 2, "XY"),
        ("XYZ", 3, "XYZ"),
        ("XYZA", 3, "XYAZ"),
        ("XYZAB", 3, "XBYAZ"),
        ("XYZABC", 3, "XBYACZ"),
        ("ABCDEF", 6, "ABCDEF"),
        ("ABCDE", 6, "ABCDE"),
        ("AB", 100, "AB"),
        ("PYTHON", 3, "POYHNT"),
        ("PYTHON", 4, "PYNTOH"),
        ("GROK", 2, "GORK"),
        ("GROK", 3, "GRKO"),
        ("ALGORITHM", 3, "ARMLOIHGT"),
        ("ALGORITHM", 5, "AMLHGTOIR"),
        ("Z", 1, "Z"),
        ("ZZ", 2, "ZZ"),
        ("ZZZ", 3, "ZZZ"),
        ("ZZZZ", 2, "ZZZZ"),
        ("ZZZZZ", 3, "ZZZZZ"),
        ("ZZZZZZ", 4, "ZZZZZZ"),
        ("ABC DEF GHI", 3, "ADGB E HCFI"),
        ("A B C", 2, "ABC  "),
        ("Hello, World!", 3, "Hoo!el,Wrdl l"),
        ("12345", 2, "13524"),
        ("123456", 3, "152463"),
        ("1234567", 4, "1726354"),
        ("AAAAAAAAAA", 3, "AAAAAAAAAA"),
        ("ABCABCABC", 3, "ABCBACBCA"),
        ("ABCABCABC", 2, "ACBACBACB"),
        ("ABCABCABC", 4, "AABCBCBCA"),
        ("ABACADA", 3, "AABCDAA"),
        ("ABACADA", 4, "AABDAAC"),
        ("THISISAZIGZAGEXAMPLE", 5, "TIMHZGAPIAZXLSSAEEIG"),
        ("LONGSTRINGWITHLENGTH", 3, "LSNTNOGTIGIHEGHNRWLT"),
        ("LONGSTRINGWITHLENGTH", 6, "LWOGIHNNTTGIHGSRLNTE"),
        ("AAAAAAAAAAAAAAAAAAAA", 1, "AAAAAAAAAAAAAAAAAAAA"),
        ("AAAAAAAAAAAAAAAAAAAA", 20, "AAAAAAAAAAAAAAAAAAAA"),
        ("AAAAAAAAAAAAAAAAAAAA", 21, "AAAAAAAAAAAAAAAAAAAA"),
        ("0123456789", 3, "0481357926"),
        ("0123456789", 4, "0615724839"),
        ("0123456789", 2, "0246813579"),
        ("0123456789", 5, "0817926354"),
        ("9876543210", 3, "9518642073"),
        ("!@#$%^&*()", 3, "!%(@$^*)#&"),
        ("!@#$%^&*()", 4, "!&@^*#%($)"),
        ("SevenChars", 3, "SnreeCasvh"),
        ("ABCD EFG", 3, "A BDEGCF"),
        ("SingleChar", 1, "SingleChar"),
    ];

    for (s, k, expected) in tests {
        let result = Solution::convert(s.to_string(), k);
        if result != expected {
            println!("s: {}, k: {}, e: {}", s, k, expected);
            println!("> {}", result);
            println!("^^^ ERR");
            return;
        }
    }

    println!("PASSED");
}
