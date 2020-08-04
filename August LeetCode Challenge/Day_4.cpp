class Solution {
	public boolean isPowerOfFour(int num) {
		return num == 1 ? true : num > 0 && (num & (num - 1)) == 0 && (num % 10 == 4 || num % 10 == 6);
	}
}