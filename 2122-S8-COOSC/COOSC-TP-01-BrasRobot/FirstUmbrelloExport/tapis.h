
#ifndef TAPIS_H
#define TAPIS_H
#include "systeme.h"

#include <string>
#include vector



/**
  * class tapis
  * 
  */

class tapis : public systeme
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  tapis ();

  /**
   * Empty Destructor
   */
  virtual ~tapis ();

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  



  /**
   * @return undef
   */
  undef C ()
  {
  }

protected:

  // Static Protected attributes
  //  

  // Protected attributes
  //  

public:


  // Protected attribute accessor methods
  //  

protected:

public:


  // Protected attribute accessor methods
  //  

protected:


private:

  // Static Private attributes
  //  

  // Private attributes
  //  

  undef EtatCapteur;
public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of EtatCapteur
   * @param new_var the new value of EtatCapteur
   */
  void setEtatCapteur (undef new_var)   {
      EtatCapteur = new_var;
  }

  /**
   * Get the value of EtatCapteur
   * @return the value of EtatCapteur
   */
  undef getEtatCapteur ()   {
    return EtatCapteur;
  }
private:


  void initAttributes () ;

};

#endif // TAPIS_H
