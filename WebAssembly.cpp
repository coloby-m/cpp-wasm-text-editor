#include <tuple>
#include <mutex>
#include <thread>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <pthread.h>
#include <emscripten.h>
#include <shared_mutex>
#include "WebAssembly.h"
#include <emscripten/threading.h>

static int pthread_finished{0};
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER; 
        
  mcs::library<std::string, int>* L = new mcs::library<std::string, int>[4];

  

extern "C" { // SEARCH BLOCK

  struct SearchArgs 
    { 
        std::string text; 
        std::string print;
        int opc;
    };


  void* update_variable(int cndc){ 

      while(pthread_finished<=5)
        {
           if(pthread_finished == 5)
            { 
                if(cndc != 10){ 

                      if(L[0].seeAll.empty())
                       {  
                         if( L[0].js_callback_noT != nullptr)
                            {
                                 L[0].js_callback_noT(1);
                            };
                        }
                       else
                        { 
                            for (size_t i = 0; i < L[0].seeAll.size(); i++)
                           {
                             const auto& title = std::get<0>(*L[0].seeAll[i]);

                             if(L[0].js_callback_T != nullptr)
                              {
                                 L[0].js_callback_T(title.c_str(),i);
                               };
                           }
                           
                        };
                }
                else{L[0].js_callback_noT(3);}
 
              break;
            } 
        };

       
      return nullptr;
    };

  void* return_threads(void* arg) { auto* args = reinterpret_cast<SearchArgs*>(arg);
  
        pthread_mutex_lock(&mtx);

          L[0].SeeText(args->opc,args->print,args->text,0);

          pthread_finished++;

        pthread_mutex_unlock(&mtx); delete args;
                
       return nullptr;
    };

 EMSCRIPTEN_KEEPALIVE
  void especific_t(int id,int opc, int i){ 

        if(opc == 2){

           if(i == 0){ L[0].SeeText(1,id);} 

           else{L[0].SeeText(3,id);}
        }

        else{  auto ptr_t = L[0].seeAll[id];

            const auto& title = std::get<0>(*ptr_t);
            const auto& author = std::get<1>(*ptr_t);
            const auto& text = std::get<2>(*ptr_t);

            if(L[0].js_callback_allT != nullptr)
            {
               L[0].js_callback_allT(title.c_str(),author.c_str(),text.c_str());
             }
        }

   };

 EMSCRIPTEN_KEEPALIVE
  void random_txt(){
      
      mcs::V<int> vv;

      vv.randomText(L); 
        
  };

 EMSCRIPTEN_KEEPALIVE
  void clear_vetor(){L[0].seeAll.clear();};

 EMSCRIPTEN_KEEPALIVE
  void search(int FoQ, char* t, void(*js_callback)(const char*,const int), void(*js_callback_null)(const int),  void(*js_callback_other)(const char*,const char*,const char*) )
    {
         L[0].js_callback_T = js_callback;
         L[0].js_callback_noT = js_callback_null;
         L[0].js_callback_allT =js_callback_other;

         if(FoQ == 1){L[0].SeeText(std::string(t));}

         else if(FoQ == 2){ L[0].SeeText(2,0); }
                  
         else if(FoQ == 6 or FoQ == 7){  L[0].SeeText(FoQ); }


         else if(FoQ == 8 or 9 or FoQ == 10){ pthread_finished = 0; std::string print;

                        if(FoQ==9){ print = "print_all"; }

                        else if(FoQ == 8){print = "print_search"; }

                        else if(FoQ == 10){print = "delet";}

                pthread_t worker_search_sector_a;
                auto* args = new SearchArgs{std::string(t), print,0};
                if (pthread_create(&worker_search_sector_a, nullptr, return_threads, args) == 0)
                    pthread_detach(worker_search_sector_a);
                else
                    delete args;

                pthread_t worker_search_sector_b;
                auto* args2 = new SearchArgs{std::string(t), print,1};
                if (pthread_create(&worker_search_sector_b, nullptr, return_threads, args2) == 0)
                    pthread_detach(worker_search_sector_b);
                else
                    delete args2;

                pthread_t worker_search_sector_c;
                auto* args3 = new SearchArgs{std::string(t), print,2};
                if (pthread_create(&worker_search_sector_c, nullptr, return_threads, args3) == 0)
                    pthread_detach(worker_search_sector_c);
                else
                    delete args3;

                pthread_t worker_search_sector_d;
                auto* args4 = new SearchArgs{std::string(t), print,3};
                if (pthread_create(&worker_search_sector_d, nullptr, return_threads, args4) == 0)
                    pthread_detach(worker_search_sector_d);
                else
                    delete args4; 

                pthread_t worker_search_sector_e;
                auto* args5 = new SearchArgs{std::string(t), print,4};
                if (pthread_create(&worker_search_sector_e, nullptr, return_threads, args5) == 0)
                    pthread_detach(worker_search_sector_e);
                else
                    delete args5;

         update_variable(FoQ);
                
            };
         
       std::free(t); 
    };
}; // END OF THE RESEARCH BLOCK

extern "C" { // REGISTRATION BLOCK
  
 EMSCRIPTEN_KEEPALIVE
  void Register(char* title, char* text, char* author, int gender)
   { 

      std::string Title = title; std::string Author = author; std::string Text = text;
    
      mcs::SmallTaxt<std::string, int> S(Title,Author,Text);
      L[0].SaveText(std::move(S),gender);

        std::free(title);
        std::free(text);
        std::free(author);
        

       // delete[] L;
    };
}	// END OF RECORD BLOCK

