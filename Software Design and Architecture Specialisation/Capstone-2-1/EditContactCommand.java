package com.example.sharingapp;

import android.content.Context;

public class EditContactCommand extends Command {
    private ContactList contact_list;
    private Contact oldContact, newContact;
    private Context context;

    public EditContactCommand(ContactList contact_list, Contact oldContact, Contact newContact, Context context) {
        this.contact_list = contact_list;
        this.oldContact = oldContact;
        this.newContact = newContact;
        this.context = context;
    }

    public void execute(){
        contact_list.deleteContact(oldContact);
        contact_list.addContact(newContact);
        setIsExecuted(contact_list.saveContacts(context));
    }
}
