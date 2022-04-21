Architecture GrapheTroisEtats of Commande is

-- ceci est un commentaire

-- d'abord la déclaration des variables internes
Type Etat Is (Etat1, Etat2, Etat3);
Signal EtatPresent, EtatSuivant : Etat;

Begin
  -- Ensuite le process décrivant le bloc F
  Process (EtatPresent, a, b)
    Begin
        Case EtatPresent Is
          When Etat1 =>
            IF (a = '1') THEN EtatSuivant <= Etat2;
            ELSIF (b = '1') THEN EtatSuivant <= Etat3;
            ELSE EtatSuivant <= EtatPresent;
            End IF;

          When Etat2 =>
            IF (a = '0') THEN EtatSuivant <= Etat1;
            ELSIF (b = '1') THEN EtatSuivant <= Etat3;
            ELSE EtatSuivant <= EtatPresent;
            End IF;

          When Etat3 =>
            IF (b = '0') THEN EtatSuivant <= Etat1;
            ELSE EtatSuivant <= EtatPresent;
            End IF;

    End Case;
  End Process;

  -- Ensuite le process décrivant le bloc M
  Process (Horloge, Init)
    Begin
      If (Init = '1') then Etatpresent <= Etat1;
      Elsif (Horloge'EVENT) And (Horloge = '1')) THEN EtatPresent <= EtatSuivant ;
      End if ;
  End Process;

  -- Enfin les affectations décrivant le bloc G
  S <= '1' When ((EtatPresent = Etat2) Or (EtatPresent = Etat3)) Else '0';

End GrapheTroisEtats;
