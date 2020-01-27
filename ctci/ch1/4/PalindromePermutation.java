import java.util.HashMap;
import java.util.Map;

public class PalindromePermutation {

    private static Boolean isPermutationOfPalindrome(String str) {
	Map<Character,Integer> map = new HashMap<>();
	for (char c : str.toLowerCase().toCharArray()) {
	    if (!Character.isWhitespace(c)) {
		map.put(c, map.getOrDefault(c, 0) + 1);
	    }
	}
	
	boolean odd_character = false;
	for (int value : map.values()) {
	    if (value % 2 != 0) {
		if (odd_character) {
		    return false;
		}
		else {
		    odd_character = true;
		}
	    }
	}
	return true;       
    }
    
    public static void main(String[] args) {
	System.out.println(isPermutationOfPalindrome("Tact Coa"));
    }
}
