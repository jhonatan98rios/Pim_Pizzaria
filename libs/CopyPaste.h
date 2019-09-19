int CopyPaste(source, target){
        int ch;
        FILE *fp1, *fp2;

        /* char source[] = "text.txt";
        char target[] = "../../data/text.txt"; */

        fopen(target, "a");

        /* open the source file in read mode */
        fp1 = fopen(source, "r");
        /* open the destination file in write mode */
        fp2 = fopen(target, "w");

        /* error handling */
        if (!fp1) {
                printf("Unable to open source file to read!!\n");
                fclose(fp2);
                return 0;
        }

        if (!fp2) {
                printf("Unable to open target file to write\n");
                return 0;
        }

        /* copying contents of source file to target file */
        while ((ch = fgetc(fp1)) != EOF) {
                fputc(ch, fp2);
        }

        /* closing the opened files */
        fclose(fp1);
        fclose(fp2);

        /* removing the source file */
        remove(source);
        return 0;
  }