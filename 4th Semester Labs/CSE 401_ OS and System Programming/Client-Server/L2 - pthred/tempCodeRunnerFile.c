// start child thread
        if (pthread_create(&thread_id, NULL, dostuff, (void *)&new_sockfd) < 0)
        {
            perror("ERROR create thread");
            exit(1);
        }

        pthread_detach(thread_id); // don't track it