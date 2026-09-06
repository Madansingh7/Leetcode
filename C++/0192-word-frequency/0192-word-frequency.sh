# Read from the file words.txt and output the word frequency list to stdout.
awk '{
    for(i=1;i<=NF;i++) cnt[$i]++
    } 
END{
    for(w in cnt) print w, cnt[w]
    }' words.txt | sort -nrk2