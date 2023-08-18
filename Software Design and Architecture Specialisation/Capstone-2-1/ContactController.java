package com.example.sharingapp;
/**
 * Capstone Assg 2.2
 * Jonathan Edward Teo Jun Rui
 */
/**
 * ContactController is responsible for all communication between views and Contact object
 */
public class ContactController {

    private Contact contact;

    public ContactController(Contact contact) {
        this.contact = contact;
    }

    public String getUsername(){
        return contact.getUsername();
    }
    public String getEmail() {
        return contact.getEmail();
    }
    public String getId() {
        return contact.getId();
    }

    public void setUsername(String username){
        contact.setUsername(username);
    }
    public void setEmail(String email){
        contact.setEmail(email);
    }
    public void setId(){
        contact.setId();
    }
    public void updateId(String id){
        contact.updateId(id);
    }

    public Contact getContact(){
        return contact;
    }

    public void addObserver(Observer observer){
        contact.addObserver(observer);
    }
    public void removeObserver(Observer observer){
        contact.removeObserver(observer);
    }
}
