/*
 * This file contains code from "C++ Primer, Fourth Edition", by Stanley B.
 * Lippman, Jose Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2005 by Objectwrite, Inc., Jose Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Contracts Department
 * 	75 Arlington Street, Suite 300
 * 	Boston, MA 02216
 * 	Fax: (617) 848-7047
*/ 

#include <string>
#include <iostream>

class Endangered {
public:
    enum Status { critical, environment, improving };
    Endangered(Status stat): animal_status(stat) { }
    virtual ~Endangered();
    virtual std::ostream& print(std::ostream&) const;
    virtual void highlight() const;
    virtual int population() const;
    // ...
private:
    Status animal_status;
};

class ZooAnimal;
extern std::ostream&
operator<<(std::ostream&, const ZooAnimal&);

class ZooAnimal {
public:
    ZooAnimal();
    ZooAnimal(std::string animal, bool exhibit,
              std::string family): nm(animal), 
                                   exhibit_stat(exhibit), 
                                   fam_name(family) { } 
    virtual ~ZooAnimal();

    virtual std::ostream& print(std::ostream&) const;

    // accessors
    std::string name() const { return nm; }
    std::string family_name() const { return fam_name; }
    bool onExhibit() const { return exhibit_stat; }
    // ...
protected:
    std::string nm;
    bool        exhibit_stat;
    std::string fam_name;
    // ...
private:
};

class Bear : public ZooAnimal {
enum DanceType { two_left_feet, macarena, fandango, waltz };
public:
    Bear();
    Bear(std::string name, bool onExhibit=true, 
         std::string family = "Bear"):
                         ZooAnimal(name, onExhibit, family),
                         ival(0), dancetype(two_left_feet) { }

    virtual std::ostream &print(std::ostream&) const;
    virtual int toes() const;
    int mumble(int);
    void dance(DanceType) const;

    virtual ~Bear();
private:
    int         ival;
    DanceType   dancetype;
};
class Panda : public Bear, public Endangered {
public:
    Panda();
    Panda(std::string name, bool onExhibit=true);
    virtual ~Panda();
    // no print function in this version
    void highlight();
    virtual int toes();
    virtual void cuddle();
// ...
};

// explicitly initialize both base classes
Panda::Panda(std::string name, bool onExhibit)
      : Bear(name, onExhibit, "Panda"),
        Endangered(Endangered::critical) { }

// implicitly use Bear default constructor to initialize the Bear subobject
Panda::Panda()
      : Endangered(Endangered::critical) { }
