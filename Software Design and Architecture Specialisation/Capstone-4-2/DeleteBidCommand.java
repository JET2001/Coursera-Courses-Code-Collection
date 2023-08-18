package com.example.sharingapp;

import android.content.Context;

import java.util.concurrent.ExecutionException;

/**
 * Command to delete a bid
 */
public class DeleteBidCommand extends Command {
    private Bid bid;

    public DeleteBidCommand(Bid bid) {
        this.bid = bid;
    }

    // Delete bid remotely
    public void execute(){
        ElasticSearchManager.RemoveBidTask remove_bid_task = new ElasticSearchManager.RemoveBidTask();
        remove_bid_task.execute();

        try {
            if (remove_bid_task.get()) super.setIsExecuted(true);
        } catch (InterruptedException | ExecutionException e){
            e.printStackTrace();
            super.setIsExecuted(false);
        }
    }
}