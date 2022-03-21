// Modification pour communication synchrone

int main () {
  // Attention a l ordre de declaration des variables
  m1 unM1 ;
  m2 unM2 ;
  KB2 unKB2 ( & unM2 ) ;
  KB1 unKB1 ( & unM1, & unM2, & unKB2 ) ;
  KA3 unKA2 ( & unM1, & unM2, & unKB2 ) ;
  KA1 unKA1 ( & unM1, & unM2, & unKA2 ) ;

  while (1) {
    ...
  }

  return 0 ;
}
