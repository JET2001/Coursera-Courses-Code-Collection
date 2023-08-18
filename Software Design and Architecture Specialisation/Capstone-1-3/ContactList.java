package com.example.sharingapp;

import android.content.Context;

import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.lang.reflect.Type;
import java.util.ArrayList;

public class ContactList {
    private ArrayList<Contact> contacts;
    private String FILENAME = "contacts.sav";

    // Constructors
    public ContactList(){
        contacts = new ArrayList<>();
    }

    // Getters and Setters
    public ArrayList<Contact> getContacts() {
        return contacts;
    }
    public void setContacts(ArrayList<Contact> contacts) {
        this.contacts = contacts;
    }

    // Other methods
    public ArrayList<String> getAllUsernames(){
        ArrayList<String> userNames = new ArrayList<>();
        for (Contact contact : contacts){
            userNames.add(contact.getUsername());
        }
        return userNames;
    }

    public void addContact(Contact contact){
        contacts.add(contact);
    }
    public void deleteContact(Contact contact){
        contacts.remove(contact);
    }
    public Contact getContact(int idx){
        return contacts.get(idx);
    }
    public int getSize() {
        return contacts.size();
    }
    public int getIndex(Contact contact){
        int pos = 0;
        for (Contact c : contacts) {
            if (contact.getId().equals(c.getId())) {
                return pos;
            }
            pos = pos+1;
        }
        return -1;
    }
    public boolean hasContact(Contact contact){
        return contacts.contains(contact);
    }
    public Contact getContactByUsername(String username){
        Contact contact = null;
        for (Contact c : contacts){
            if (c.getUsername().equals(username)){
                contact = c;
                break;
            }
        }
        return contact;
    }
    public void loadContacts(Context context){
        try {
            FileInputStream fis = context.openFileInput(FILENAME);
            InputStreamReader isr = new InputStreamReader(fis);
            Gson gson = new Gson();
            Type listType = new TypeToken<ArrayList<Contact>>() {}.getType();
            contacts = gson.fromJson(isr, listType); // temporary
            fis.close();
        } catch (FileNotFoundException e) {
            contacts = new ArrayList<>();
        } catch (IOException e) {
            contacts = new ArrayList<>();
        }
    }
    public void saveContacts(Context context){
        try {
            FileOutputStream fos = context.openFileOutput(FILENAME, 0);
            OutputStreamWriter osw = new OutputStreamWriter(fos);
            Gson gson = new Gson();
            gson.toJson(contacts, osw);
            osw.flush();
            fos.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public boolean isUsernameAvailable(String username){
        return (getContactByUsername(username) == null);
    }
}
