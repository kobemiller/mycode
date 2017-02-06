/*
 * 修改为从配置文件读取
 */
#include <sys/stat.h>
#include <unistd.h>

/*
 *使用读取文件属性的方法得到文件的大小，效率高，较稳定。
 */
unsigned long get_file_size(const char *path)
{
	unsigned long filesize = -1;
	struct stat statbuff;
	if (stat(path, &statbuff) < 0)
	{
		return filesize;
	}
	else
		filesize = statbuff.st_size;

	return filesize;
}

int verify_so()
{
	int fd_rnt, fd_sm234, fd_origin_rnt, fd_origin_sm234;
	unsigned char *p_rnt = NULL;
	unsigned char *p_sm234 = NULL;
	unsigned int len_rnt, len_sm234;

	unsigned char hash_rnt[32], hash_sm234[32];
	unsigned char origin_hash_rnt[32], origin_hash_sm234[32];

		len_rnt = get_file_size("./kobe.so");
	if (len_rnt < 0)
	{
		printf("kobe file error!\n");
		return -1;
	}
	len_sm234 = get_file_size("./miller.so");
	if (len_sm234 < 0)
	{
		printf("miller234 file error!\n");
		return -1;
	}

	/*
	 * 分配空间用来存储动态库文件内容
	 */
	p_rnt = (unsigned char *)malloc(len_rnt);
	if (p_rnt == NULL)
	{
		printf("malloc error!\n");
		return -1;
	}
	p_sm234 = (unsigned char *)malloc(len_sm234);
	if (p_sm234 == NULL)
	{
		printf("malloc error!\n");
		return -1;
	}

	/*
	 * 打开动态库文件
	 */
	fd_rnt = open("./kobe.so", O_RDONLY);
	if (fd_rnt <= 0)
	{
		printf("kobe file open error!\n");
		return -1;
	}
	fd_sm234 = open("miller.so", O_RDONLY);
	{
		printf("miller file open error!\n");
		return -1;
	}

	/*
	 * 打开写死的动态库的hash值
	 */
	fd_origin_rnt = open("./hash_rnt", O_RDONLY);
	if (fd_origin_rnt <= 0)
	{
		printf("hash_rnt file open error!\n");
		return -1;
	}
	fd_origin_sm234 = open("./hash_sm234", O_RDONLY);
	if (fd_origin_sm234 <= 0)
	{
		printf("hash_sm234 file open error!\n");
		return -1;
	}

	/*
	 * 读取写死的动态库hash值
	 */
	if ((read(fd_origin_rnt, origin_hash_rnt, 32)) == -1)
	{
		printf("hash_rnt file read error!\n");
		return -1;
	}
	if ((read(fd_origin_sm234, origin_hash_sm234, 32)) == -1)
	{
		printf("hash_sm234 file read error!\n");
		return -1;
	}

	/*
	 * 读取动态库文件内容
	 */
	if ((read(fd_rnt, p_rnt, len_rnt)) == -1)
	{
		printf("read kobe error!\n");
		return -1;
	}
	if ((read(fd_sm234, p_sm234, len_sm234)) == -1)
	{
		printf("read miller error!\n");
		return -1;
	}

	/*
	 * 对动态库内容作hash运算，调用动态库中的hash运算
	 */
	if (((sm3_hash(p_rnt, hash_rnt)) < 0) && ((sm3_hash(p_sm234, hash_sm234)) < 0))
	{
		printf("sm3_hash error!\n");
		return -1;
	}

	/*
	 * 将hash值做对比
	 */
	if ((memcpy(hash_rnt, origin_hash_rnt, 32) 
		&& (memcpy(hash_sm234, origin_hash_sm234, 32)))
	{
		printf("file is overwrited!\n");
		return -1;
	}

	printf("verify libso success!\n");

	free(p_rnt);
	free(p_sm234);

	return 0;
}
