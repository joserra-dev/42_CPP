#pragma once

#include <iostream>
#include <string>
#include <iomanip>

// Clase Contact para almacenar los datos individuales
class Contact {
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
    int id;

public:
    // Setters
    void setFname(const std::string& str) { first_name = str; }
    void setLname(const std::string& str) { last_name = str; }
    void setNname(const std::string& str) { nickname = str; }
    void setnumber(const std::string& str) { phone_number = str; }
    void setsecrets(const std::string& str) { darkest_secret = str; }
    void setid(int index) { id = index; }

    // Getters
    const std::string& get_fname() const { return first_name; }
    const std::string& get_lname() const { return last_name; }
    const std::string& get_nname() const { return nickname; }
    const std::string& get_pnumber() const { return phone_number; }
    const std::string& get_secrets() const { return darkest_secret; }
    int get_id() const { return id; }
};

// Clase PhoneBook que contiene hasta 8 contactos
class PhoneBook {
private:
    Contact user[8];
    int nb_Contact;

public:
    PhoneBook();

    int addContact();               // Añade un nuevo contacto
    int searchContact();           // Muestra la tabla y permite seleccionar
    int showContact(int index);    // Muestra los datos de un contacto específico
};


// Helpers externos (implementados en otro archivo, opcionalmente)
void set_homepage();                          // Puedes definirlo para limpiar pantalla o mostrar encabezado
void print_Contact(const std::string& str);   // Truncar o formatear los campos para tabla (10 caracteres)
