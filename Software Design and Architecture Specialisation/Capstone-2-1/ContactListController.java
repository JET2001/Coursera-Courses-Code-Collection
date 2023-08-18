package com.example.sharingapp;

import android.content.Context;

import java.util.ArrayList;
/**
 * Capstone Assg 2.2
 * Jonathan Edward Teo Jun Rui
 */
public class ContactListController {
    private ContactList contact_list;

    public ContactListController(ContactList contact_list) {
        this.contact_list = contact_list;
    }

    public void addObserver(Observer observer){
        contact_list.addObserver(observer);
    }
    public void removeObserver(Observer observer){
        contact_list.removeObserver(observer);
    }

    // ============================================
    // ContactList related methods
    // ============================================

    public ArrayList<Contact> getContacts(){
        return contact_list.getContacts();
    }
    public void setContacts(ArrayList<Contact> contacts){
        contact_list.setContacts(contacts);
    }
    public ArrayList<String> getAllUsernames(){
        return contact_list.getAllUsernames();
    }

    public void addContact(Contact contact){
        contact_list.addContact(contact);
    }
    public void deleteContact(Contact contact){
        contact_list.deleteContact(contact);
    }
    public Contact getContact(int index){
        return contact_list.getContact(index);
    }
    public int getSize(){
        return contact_list.getSize();
    }
    public Contact getContactByUsername(String username){
        return contact_list.getContactByUsername(username);
    }
    public boolean hasContact(Contact contact){
        return contact_list.hasContact(contact);
    }
    public int getIndex(Contact contact){
        return contact_list.getIndex(contact);
    }

    public boolean isUsernameAvailable(String username){
        return contact_list.isUsernameAvailable(username);
    }

    public void loadContacts(Context context){
        contact_list.loadContacts(context);
    }

    public void saveContacts(Context context){
        contact_list.saveContacts(context);
    }
}
