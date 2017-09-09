//j is the index initialized to zero char array of the string

expression(){
term(); if (p[j] == '+'){j++; expression();}
}

term(){
  factor(); if ((p[j] == '()') || letter(p[j])) term();
}

factor(){

}
