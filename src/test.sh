#!/bin/bash

# Test your program with multiple graphs

# List of graph files
graph_files=("graph_0.txt" "graph_1.txt" "graph_2.txt" "graph_3.txt" "graph_4.txt" "graph_5.txt"
            "graph_Disconnected_Components.txt" "graph_Cycles.txt"
            "graph_Duplicate_Edges.txt" "graph_Sparse_Graph.txt"
            "graph_Negative_Weight.txt" "graph_Wrong_Weight.txt" "graph_Negative_Weight_2.txt" )

# Iterate over each graph file
for file in "${graph_files[@]}"; do
    echo "Testing with $file"
    ./main "./graphs/$file" > output.txt  # Redirect console output to a file

    if [ $? -eq 0 ]; then
        echo "Test passed without Error!"
    else
        echo "Test failed! Error code: $?"
    fi
    echo "Output:"
        cat output.txt

    echo "---------------------------------------------"
done

# Remove the output file
rm output.txt