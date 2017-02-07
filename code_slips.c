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


