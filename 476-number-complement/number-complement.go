func findComplement(num int) int {
	var mask int = 1
	for mask < num {
		mask = mask << 1
	}
	if mask == num {
		return mask - 1
	}
	if mask > 1 {
		mask--
	}
	return mask ^ num
}