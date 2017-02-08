//use this to suppress gcc's `...may be used before initialized` warnings.
#ifdef lint
#define   IF_LINT(code) code
#else
#define   IF_LINT(code)   //empty
#endif

//open() examples
fd = open("startup", O_RDONLY);
if (fd == -1)
  errExit("open");

fd = open("myfile", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
if (fd == -1)
  errExit("open");

fd = open("w.log", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, S_IRUSR | S_IWUSR);
if (fd == -1)
  errExit("open");

//试图以独占方式打开文件的错误代码
{
  fd = open(argv[1], O_WRONLY);   //check if file exits
  if (fd != -1)
  {
    printf("[PID %ld] File \"%s\" already exists\n", (long)getpid(), argv[1]);
    close(fd);
  }
  else
  {
    if (errno != ENOENT)    //failed for unexpected reason
      errExit("open");
    else  //window for failure
    {
      fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
      if (fd == -1)
        errExit("open");

      printf("[PID %ld] Created file \"%s\" exclusively\n", (long)getpid(), argv[1]);
    }
  }
}

//复制文件描述符的两种方式
dup2(oldfd, newfd);
newfd = fcntl(oldfd, F_DUPFD, startfd);
