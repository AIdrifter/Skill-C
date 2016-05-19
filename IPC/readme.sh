./redirect >  default.log
./redirect 1> stdout.log
./redirect 2> stderr.log
./redirect 2> stderr.log

# file locking FIFO
./redirect 1> file_locking.log 2> file_locking.log


# resolve file locking
# redirect stderr to stdout, and stdout to file_locking.resolve
./redirect > file_locking.reslove 2>&1

# can't be used...stupid ORZ http://ozboyx.blogspot.tw/2010/05/shell-1-2.html
./redirect 2>&1 > file_locking.reslove
./redirect 2> file_locking.reslove >&2

# motocycle
# run cmd --> err happen --> no msg in stdout --> sent stdout content to test.err
# -->stderr(2) content redirect to stdout(1)
# --> msg in stdout --> sent stdout content to test.err again
ls -l test.txt > test.err 2>&1

# man bash
Note that the order of redirections is significant. For example, the
command

ls > dirlist 2>&1

directs both standard output and standard error to the file dirlist,


while the command

ls 2>&1 > dirlist

directs "only the standard output to file dirlist", because the standard
error was duplicated as standard output before the standard output was
redirected to dirlist.

# redirect stdout

close(1);
fd=open("results.txt", O_WRONLY, 0);

close(2);
fd=dup(1);

# conclusion
Before a command is executed,
its input and output may be redirected using a special notation interpreted by the shell.

# reference
http://ibookmen.blogspot.tw/2010/11/unix-2.html
