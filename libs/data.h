static char* dataAtual()
{
  /* Pega a data do sistema */
  struct tm *data_hora_atual;     
  time_t segundos; 
  time(&segundos);   
  data_hora_atual = localtime(&segundos);
  /* Converte em string "dd-mm-aaaa" */
  char data[20];
  sprintf(data, "%d-%d-%d", data_hora_atual->tm_mday, data_hora_atual->tm_mon+1, data_hora_atual->tm_year+1900);
  /* Cria o nome do arquivo de relatorios baseado na data */
  char relatorio[40];
  strcpy(relatorio, "./data/relatorio/");
  strcat(relatorio, data);
  strcat(relatorio, ".dat");

  return relatorio;
}