
#ifndef TABLE_D_INDEXAGE_H
#define TABLE_D_INDEXAGE_H
#include "systeme.h"

#include <string>
#include vector



/**
  * class table_d_indexage
  * 
  */

class table_d_indexage : public systeme
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  table_d_indexage ();

  /**
   * Empty Destructor
   */
  virtual ~table_d_indexage ();

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  



  /**
   */
  void Ti ()
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

  bool CapteurTi;
public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of CapteurTi
   * @param new_var the new value of CapteurTi
   */
  void setCapteurTi (bool new_var)   {
      CapteurTi = new_var;
  }

  /**
   * Get the value of CapteurTi
   * @return the value of CapteurTi
   */
  bool getCapteurTi ()   {
    return CapteurTi;
  }
private:


  void initAttributes () ;

};

#endif // TABLE_D_INDEXAGE_H
