func minimumPushes(word string) int {
    freq := make([]int, 26)
    for _, w := range word {
        freq[w-'a']++
    }

    sort.Sort(sort.Reverse(sort.IntSlice(freq)))

    it := 1
    sum := 0
    for i := 0; i < 26; i++ {
        sum += it * freq[i]
        if (i+1)%8 == 0 {
            it++
        }
    }

    return sum
}
