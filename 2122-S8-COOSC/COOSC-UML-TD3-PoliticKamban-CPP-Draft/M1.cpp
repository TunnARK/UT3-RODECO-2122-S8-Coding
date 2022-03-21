Class m1 : public Systeme_RdP {
  Public :
    enum nom_place { OpA1_A2, attente, OpB2 };
    m1();
};

m1 :: m1() : Systeme_RdP(3) {
  place[ attente ] = 1 ;
}

void m1 :: evolue() {
  if ( place[ attente ] && t4 ) {
    place[ attente ]-- ;
    FOpA1_A2();
    place[ OpA1_A2 ]++ ;
  }

  if ( place[ OpA1_A2 ] && t5 ) {
    place[ OpA1_A2 ]-- ;
    place[ attente ]++ ;
  }

  if ( place[ attente ] && t10 ) {
    place[ attente ]-- ;
    FOpB1();
    place[ OpB1 ]++ ;
  }

  if ( place[ OpB1 ] && t11 ) {
    place[ OpB1 ]-- ;
    place[ attente ]++ ;
  }
};
