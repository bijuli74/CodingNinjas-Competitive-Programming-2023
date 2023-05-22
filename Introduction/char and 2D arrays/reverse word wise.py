import sys

def revWords(s):
    return " ".join(s.strip().split()[::-1])

# Driver Code
if __name__ == "__main__":
  
    s=input()
    ans=revWords(s)
    sys.stdout.write(ans)
    
