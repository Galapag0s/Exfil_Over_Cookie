//Special Thanks to medium.com/from-the-scratch/http-server-what-do-you-need-to-know-to-build-a-simple-http-server-from-scratch-d1ef8945e4fa

#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const * argv[])
{
  while (true)
    {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0)
    {
      perror("CANNOT CREATE SOCKET");
      return 0;
    }

    struct sockaddr_in address;
    const int PORT = 80;

    memset((char *)&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(PORT);

    int bind_sock = bind(server_sock,(struct sockaddr *)&address,sizeof(address));
    if (bind_sock < 0)
    {
      perror("BIND FAILED");
      return 0;
    }

    int listen_sock = listen(server_sock,3);
    if (listen_sock < 0)
    {
      perror("LISTENTING");
      exit(EXIT_FAILURE);
    }
    while (true)
    {
      int accept_sock = accept(server_sock,(struct sockaddr *)&address,(socklen_t*)&address);
      if (accept_sock < 0)
      {
        perror("IN ACCEPT");
        exit(EXIT_FAILURE);
      }

      char buffer[4096] = {0};
      int valread = read( accept_sock, buffer, 4096);

      //Parse out file name
      char ch = '/';
      char *start_file = strchr(buffer,ch);
      int start_file_index = (int)(start_file - buffer);
      ch = ' ';
      char *first_space = strchr(start_file,ch);
      int end_file_index = (int)(first_space - buffer - 1);

      char *file_name = strndup(buffer+start_file_index +1, (end_file_index - start_file_index));
      printf("%s\n", file_name);

      //Create New File For Host if it doesn't exist
      if ( access(file_name, F_OK) != -1)
      {
        printf("YOUR FILE EXISTS\n");
        //Add Contents
      } else {
        printf("YOUR FILE DOESN'T EXIST\n");
        FILE *file_pointer;
        file_pointer = fopen(file_name,"w");
        if (file_pointer == NULL)
        {
          printf("UNABLE TO WRITE FILE");
          exit(EXIT_FAILURE);
        }
        char data[100000000];
        //will write sections of the cookie data to a buffer and then to a file.
        fputs(file_name,file_pointer);
        fclose(file_pointer);
        printf("FILE WRITE FINISEHD\n");

        //Check If Its a Legit Request
        //Make File and write content
      }


      printf("%s\n", buffer);
      if (valread < 0)
      {
        printf("NO BYTES ARE THERE TO READ");
      }
      char const *response = "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\r\n<html xmlns=\"http://www.w3.org/1999/xhtml\">\r\n  <head>\r\n    <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\" />\r\n    <title>Apache2 Debian Default Page: It works</title>\r\n    <style type=\"text/css\" media=\"screen\">\r\n  * {\r\n    margin: 0px 0px 0px 0px;\r\n    padding: 0px 0px 0px 0px;\r\n  }\r\n\r\n  body, html {\r\n    padding: 3px 3px 3px 3px;\r\n\r\n    background-color: #D8DBE2;\r\n\r\n    font-family: Verdana, sans-serif;\r\n    font-size: 11pt;\r\n    text-align: center;\r\n  }\r\n\r\n  div.main_page {\r\n    position: relative;\r\n    display: table;\r\n\r\n    width: 800px;\r\n\r\n    margin-bottom: 3px;\r\n    margin-left: auto;\r\n    margin-right: auto;\r\n    padding: 0px 0px 0px 0px;\r\n\r\n    border-width: 2px;\r\n    border-color: #212738;\r\n    border-style: solid;\r\n\r\n    background-color: #FFFFFF;\r\n\r\n    text-align: center;\r\n  }\r\n\r\n  div.page_header {\r\n    height: 99px;\r\n    width: 100%;\r\n\r\n    background-color: #F5F6F7;\r\n  }\r\n\r\n  div.page_header span {\r\n    margin: 15px 0px 0px 50px;\r\n\r\n    font-size: 180%;\r\n    font-weight: bold;\r\n  }\r\n\r\n  div.page_header img {\r\n    margin: 3px 0px 0px 40px;\r\n\r\n    border: 0px 0px 0px;\r\n  }\r\n\r\n  div.table_of_contents {\r\n    clear: left;\r\n\r\n    min-width: 200px;\r\n\r\n    margin: 3px 3px 3px 3px;\r\n\r\n    background-color: #FFFFFF;\r\n\r\n    text-align: left;\r\n  }\r\n\r\n  div.table_of_contents_item {\r\n    clear: left;\r\n\r\n    width: 100%;\r\n\r\n    margin: 4px 0px 0px 0px;\r\n\r\n    background-color: #FFFFFF;\r\n\r\n    color: #000000;\r\n    text-align: left;\r\n  }\r\n\r\n  div.table_of_contents_item a {\r\n    margin: 6px 0px 0px 6px;\r\n  }\r\n\r\n  div.content_section {\r\n    margin: 3px 3px 3px 3px;\r\n\r\n    background-color: #FFFFFF;\r\n\r\n    text-align: left;\r\n  }\r\n\r\n  div.content_section_text {\r\n    padding: 4px 8px 4px 8px;\r\n\r\n    color: #000000;\r\n    font-size: 100%;\r\n  }\r\n\r\n  div.content_section_text pre {\r\n    margin: 8px 0px 8px 0px;\r\n    padding: 8px 8px 8px 8px;\r\n\r\n    border-width: 1px;\r\n    border-style: dotted;\r\n    border-color: #000000;\r\n\r\n    background-color: #F5F6F7;\r\n\r\n    font-style: italic;\r\n  }\r\n\r\n  div.content_section_text p {\r\n    margin-bottom: 6px;\r\n  }\r\n\r\n  div.content_section_text ul, div.content_section_text li {\r\n    padding: 4px 8px 4px 16px;\r\n  }\r\n\r\n  div.section_header {\r\n    padding: 3px 6px 3px 6px;\r\n\r\n    background-color: #8E9CB2;\r\n\r\n    color: #FFFFFF;\r\n    font-weight: bold;\r\n    font-size: 112%;\r\n    text-align: center;\r\n  }\r\n\r\n  div.section_header_red {\r\n    background-color: #CD214F;\r\n  }\r\n\r\n  div.section_header_grey {\r\n    background-color: #9F9386;\r\n  }\r\n\r\n  .floating_element {\r\n    position: relative;\r\n    float: left;\r\n  }\r\n\r\n  div.table_of_contents_item a,\r\n  div.content_section_text a {\r\n    text-decoration: none;\r\n    font-weight: bold;\r\n  }\r\n\r\n  div.table_of_contents_item a:link,\r\n  div.table_of_contents_item a:visited,\r\n  div.table_of_contents_item a:active {\r\n    color: #000000;\r\n  }\r\n\r\n  div.table_of_contents_item a:hover {\r\n    background-color: #000000;\r\n\r\n    color: #FFFFFF;\r\n  }\r\n\r\n  div.content_section_text a:link,\r\n  div.content_section_text a:visited,\r\n   div.content_section_text a:active {\r\n    background-color: #DCDFE6;\r\n\r\n    color: #000000;\r\n  }\r\n\r\n  div.content_section_text a:hover {\r\n    background-color: #000000;\r\n\r\n    color: #DCDFE6;\r\n  }\r\n\r\n  div.validator {\r\n  }\r\n    </style>\r\n  </head>\r\n  <body>\r\n    <div class=\"main_page\">\r\n      <div class=\"page_header floating_element\">\r\n        <img src=\"/icons/openlogo-75.png\" alt=\"Debian Logo\" class=\"floating_element\"/>\r\n        <span class=\"floating_element\">\r\n          Apache2 Debian Default Page\r\n        </span>\r\n      </div>\r\n<!--      <div class=\"table_of_contents floating_element\">\r\n        <div class=\"section_header section_header_grey\">\r\n          TABLE OF CONTENTS\r\n        </div>\r\n        <div class=\"table_of_contents_item floating_element\">\r\n          <a href=\"#about\">About</a>\r\n        </div>\r\n        <div class=\"table_of_contents_item floating_element\">\r\n          <a href=\"#changes\">Changes</a>\r\n        </div>\r\n        <div class=\"table_of_contents_item floating_element\">\r\n          <a href=\"#scope\">Scope</a>\r\n        </div>\r\n        <div class=\"table_of_contents_item floating_element\">\r\n          <a href=\"#files\">Config files</a>\r\n        </div>\r\n      </div>\r\n-->\r\n      <div class=\"content_section floating_element\">\r\n\r\n\r\n        <div class=\"section_header section_header_red\">\r\n          <div id=\"about\"></div>\r\n          It works!\r\n        </div>\r\n        <div class=\"content_section_text\">\r\n          <p>\r\n                This is the default welcome page used to test the correct \r\n                operation of the Apache2 server after installation on Debian systems.\r\n                If you can read this page, it means that the Apache HTTP server installed at\r\n                this site is working properly. You should <b>replace this file</b> (located at\r\n                <tt>/var/www/html/index.html</tt>) before continuing to operate your HTTP server.\r\n          </p>\r\n\r\n\r\n          <p>\r\n                If you are a normal user of this web site and don't know what this page is\r\n                about, this probably means that the site is currently unavailable due to\r\n                maintenance.\r\n                If the problem persists, please contact the site's administrator.\r\n          </p>\r\n\r\n        </div>\r\n        <div class=\"section_header\">\r\n          <div id=\"changes\"></div>\r\n                Configuration Overview\r\n        </div>\r\n        <div class=\"content_section_text\">\r\n          <p>\r\n                Debian's Apache2 default configuration is different from the\r\n                upstream default configuration, and split into several files optimized for\r\n                interaction with Debian tools. The configuration system is\r\n                <b>fully documented in\r\n                /usr/share/doc/apache2/README.Debian.gz</b>. Refer to this for the full\r\n                documentation. Documentation for the web server itself can be\r\n                found by accessing the <a href=\"/manual\">manual</a> if the <tt>apache2-doc</tt>\r\n                package was installed on this server.\r\n\r\n          </p>\r\n          <p>\r\n                The configuration layout for an Apache2 web server installation on Debian systems is as follows:\r\n          </p>\r\n          <pre>\r\n/etc/apache2/\r\n|-- apache2.conf\r\n|       `--  ports.conf\r\n|-- mods-enabled\r\n|       |-- *.load\r\n|       `-- *.conf\r\n|-- conf-enabled\r\n|       `-- *.conf\r\n|-- sites-enabled\r\n|       `-- *.conf\r\n          </pre>\r\n          <ul>\r\n                        <li>\r\n                           <tt>apache2.conf</tt> is the main configuration\r\n                           file. It puts the pieces together by including all remaining configuration\r\n                           files when starting up the web server.\r\n                        </li>\r\n\r\n                        <li>\r\n                           <tt>ports.conf</tt> is always included from the\r\n                           main configuration file. It is used to determine the listening ports for\r\n                           incoming connections, and this file can be customized anytime.\r\n                        </li>\r\n\r\n                        <li>\r\n                           Configuration files in the <tt>mods-enabled/</tt>,\r\n                           <tt>conf-enabled/</tt> and <tt>sites-enabled/</tt> directories contain\r\n                           particular configuration snippets which manage modules, global configuration\r\n                           fragments, or virtual host configurations, respectively.\r\n                        </li>\r\n\r\n                        <li>\r\n                           They are activated by symlinking available\r\n                           configuration files from their respective\r\n                           *-available/ counterparts. These should be managed\r\n                           by using our helpers\r\n                           <tt>\r\n                                a2enmod,\r\n                                a2dismod,\r\n                           </tt>\r\n                           <tt>\r\n                                a2ensite,\r\n                                a2dissite,\r\n                            </tt>\r\n                                and\r\n                           <tt>\r\n                                a2enconf,\r\n                                a2disconf\r\n                           </tt>. See their respective man pages for detailed information.\r\n                        </li>\r\n\r\n                        <li>\r\n                           The binary is called apache2. Due to the use of\r\n                           environment variables, in the default configuration, apache2 needs to be\r\n                           started/stopped with <tt>/etc/init.d/apache2</tt> or <tt>apache2ctl</tt>.\r\n                           <b>Calling <tt>/usr/bin/apache2</tt> directly will not work</b> with the\r\n                           default configuration.\r\n                        </li>\r\n          </ul>\r\n        </div>\r\n\r\n        <div class=\"section_header\">\r\n            <div id=\"docroot\"></div>\r\n                Document Roots\r\n        </div>\r\n\r\n        <div class=\"content_section_text\">\r\n            <p>\r\n                By default, Debian does not allow access through the web browser to\r\n                <em>any</em> file apart of those located in <tt>/var/www</tt>,\r\n                <a href=\"http://httpd.apache.org/docs/2.4/mod/mod_userdir.html\" rel=\"nofollow\">public_html</a>\r\n                directories (when enabled) and <tt>/usr/share</tt> (for web\r\n                applications). If your site is using a web document root\r\n                located elsewhere (such as in <tt>/srv</tt>) you may need to whitelist your\r\n                document root directory in <tt>/etc/apache2/apache2.conf</tt>.\r\n            </p>\r\n            <p>\r\n                The default Debian document root is <tt>/var/www/html</tt>. You\r\n                can make your own virtual hosts under /var/www. This is different\r\n                to previous releases which provides better security out of the box.\r\n            </p>\r\n        </div>\r\n\r\n        <div class=\"section_header\">\r\n          <div id=\"bugs\"></div>\r\n                Reporting Problems\r\n        </div>\r\n        <div class=\"content_section_text\">\r\n          <p>\r\n                Please use the <tt>reportbug</tt> tool to report bugs in the\r\n                Apache2 package with Debian. However, check <a\r\n                href=\"http://bugs.debian.org/cgi-bin/pkgreport.cgi?ordering=normal;archive=0;src=apache2;repeatmerged=0\"\r\n                rel=\"nofollow\">existing bug reports</a> before reporting a new bug.\r\n          </p>\r\n          <p>\r\n                Please report bugs specific to modules (such as PHP and others)\r\n                to respective packages, not to the web server itself.\r\n          </p>\r\n        </div>\r\n\r\n\r\n\r\n\r\n      </div>\r\n    </div>\r\n    <div class=\"validator\">\r\n    </div>\r\n  </body>\r\n</html>\r\n\r\n";
      write(accept_sock, response, strlen(response));

      close(accept_sock);
    }
  }

}
