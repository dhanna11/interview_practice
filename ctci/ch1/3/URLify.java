public class URLify {

    private static void urlify(char[] charArray, int trueLength) {
	int spaceCount = 0;
	int index = 0;
	for (int i = 0; i < trueLength; i++) {
	    if (charArray[i] == ' ' ) {
		spaceCount++;
	    }
	}
	index = trueLength + spaceCount * 2 - 1;
	if (trueLength < charArray.length) charArray[trueLength] = '\0';

	for (int i = trueLength - 1; i >= 0; i--) {
	    if (charArray[i] == ' ') {
		charArray[index] = '0';
		charArray[index - 1] = '2';
		charArray[index - 2] = '%';
		index -= 3;
	    } else {
		charArray[index] = charArray[i];
		index--;
	    }	    	    
	}
    }
	
    public static void main(String[] args) {
	char[] str0 = "Mr John Smith        ".toCharArray();
	urlify(str0,13);
	System.out.println(str0);
    }
}
