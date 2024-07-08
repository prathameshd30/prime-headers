if [ -z "$( ls -A '/home/PDash/Github_Workspace/prime-headers/empty' )" ]; then
       echo "Valgrind Test Passed"
       else
       exit 1
       fi