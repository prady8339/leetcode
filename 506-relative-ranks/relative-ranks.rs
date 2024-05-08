struct Pair<T, U> {
    first: T,
    second: U,
}

impl Solution {
    pub fn find_relative_ranks(score: Vec<i32>) -> Vec<String> {
        let mut pairs: Vec<Pair<i32, usize>> = score.iter().enumerate()
            .map(|(i, &s)| Pair { first: s, second: i })
            .collect();

        pairs.sort_by_key(|pair| -pair.first); // Sort by score in descending order

        let mut ans: Vec<String> = vec![String::new(); score.len()];

        for (i, pair) in pairs.iter().enumerate() {
            let idx = pair.second;
            match i {
                0 => ans[idx] = "Gold Medal".to_string(),
                1 => ans[idx] = "Silver Medal".to_string(),
                2 => ans[idx] = "Bronze Medal".to_string(),
                _ => ans[idx] = (i + 1).to_string(),
            }
        }

        ans
    }
}



// [capture clause](parameters) -> return_type { 
//     // Function body
// }