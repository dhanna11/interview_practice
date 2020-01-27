import java.io.*;
import java.util.*;

class Solution {
  
  class NFA {
    
    public NFA(char c, char prev) {
      switch (c) {
          case: '.':
            return wildCardNFA();
          case: '*':
            return kleeneStarNFA(prev);
          default: 
            return charNFA(c);
      }  
    }
    
    private kleeneStarNFA(char c) {
      this.start = new State();
      this.end = new State();
      start.addNextState(ε, this.end);
      State innerNFAStart = new State();
      State innerNFAEnd = new State();
      innerNFAStart.addNextState(c, innerNFAEnd);
      innerNFAEnd.addNextState(ε, innerNFAStart);
      innerNFAEnd.addNextState(ε, this.end);
    }
    
    private wildCardNFA() {
      this.start = new State();
      start.addNextState(ε, end);
      this.end = new State();
      
    }
    private charNFA(char c) {
      this.start = new State();
      this.end = new State();
      start.addNextState(c,end);
      return this;
      
    }
    State start, end;
    
    
  }
  
  class State {
      void setNextState(char c, State state)  {        
        List<State> states = map.get(c);
        if (states == null)   {
          states = new ArrayList<State>();
          map.put(c, states);
        }
        states.add(state);
      }
      
      map<char, List<State>> nextState;     
    
  }
  
  static boolean isMatch(String text, String pattern) {
    // your code goes here
  }

  public static void main(String[] args) {

  }

}
