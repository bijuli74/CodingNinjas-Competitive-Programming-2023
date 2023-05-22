void reverse(char input[], int start, int end){
while(start < end){
  swap(input[start++], input[end--]);
  }
}

void reverseStringWordWise(char input[]) {
  int previousSpaceIndex = -1;
  int i = 0;
  for(; input[i] != '\0'; i++) {
    if(input[i] == ' ') {
      reverse(input, previousSpaceIndex + 1, i - 1);
      previousSpaceIndex = i;
    }
  }
  reverse(input, previousSpaceIndex + 1, i - 1);
  reverse(input, 0, i - 1);
}
