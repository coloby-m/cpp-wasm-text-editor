#pragma once

#include <map>
#include <mutex>
#include <tuple> 
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <random>
#include <ranges>
#include <string>
#include <thread>
#include <future>
#include <utility>
#include <iostream>
#include <algorithm>
#include <type_traits>
#include <condition_variable>

namespace mcs 
{ 

 template <typename T1, typename T2>
 class SmallTaxt{
    public:
    T1 tt;
    T1 tx;
    T1 at;
    T2 data;
    SmallTaxt()= default;
    SmallTaxt(T1 titulo,T1 autor,T1 texto)
               :tt(titulo),at(autor),tx(texto)
               {};
    virtual ~SmallTaxt(){};
    
    std::tuple<T1,T1,T1> amz{tt,at,tx};

    auto* PrintBook()const{ return &amz ;};

    T1 Search()const{return tt;}

   };

 template <typename T1, typename T2>
 struct library{ T2 al;
     
     void(*js_callback_allT)(const char*,const char*,const char*) = nullptr;
     void (*js_callback_T)(const char*,const int) = nullptr;
     void (*js_callback_noT)(const int) = nullptr;

    std::vector<const std::tuple<T1,T1,T1>*> seeAll;

    std::map<T2,mcs::SmallTaxt<T1,T2>> sector_a;
    std::map<T2,mcs::SmallTaxt<T1,T2>> sector_b;
    std::map<T2,mcs::SmallTaxt<T1,T2>> sector_c;
    std::map<T2,mcs::SmallTaxt<T1,T2>> sector_d;
    std::map<T2,mcs::SmallTaxt<T1,T2>> sector_e;
    std::map<T2,mcs::SmallTaxt<T1,T2>> sector_f;
    
    std::queue<mcs::SmallTaxt<T1,T2>> Fifo;
    std::stack<mcs::SmallTaxt<T1,T2>> Lifo;  

    T2 save_object(SmallTaxt<T1,T2>&& obj, std::map<T2,mcs::SmallTaxt<T1,T2>>& sector){ 

                          int nextId = sector.empty() ? 0 : sector.rbegin()->first + 1;

                                sector[nextId] = std::move(obj);
       return 0;    
    };


   T2 SaveText(SmallTaxt<T1,T2>&& obj,T2 genero)noexcept{ 

                  if(Fifo.empty()){Fifo.push(obj);};

                  if(!Lifo.empty()){Lifo.pop();};

                  Lifo.push(obj);

                  switch(genero)
                     { 
                          case 0:save_object(std::move(obj),sector_a);
                                  break;
                          case 1:save_object(std::move(obj),sector_b);
                                  break;
                          case 2:save_object(std::move(obj),sector_c);
                                  break;
                          case 3:save_object(std::move(obj),sector_d);
                                  break;
                          case 4:save_object(std::move(obj),sector_e);
                                  break; 
                          case 5:save_object(std::move(obj),sector_f);
                                  break;
                      };
                                      
            return 0;
    };

    int Sectors( std::map<T2,mcs::SmallTaxt<T1,T2>>& sector, const T1& sch, const T1& what, int nA ){

         if (sector.empty()){

              if(sch == "random"){ js_callback_noT(1); 

                  return 0;
              }
             else return 0;
         }

         if (sch == "print_all") { 

               for(const auto& [id, title] : sector){ seeAll.push_back(title.PrintBook()) ;};
          } 

          else if (sch == "print_search") { 

              for (const auto& [id, title] : sector) {

                      if (title.Search() == what) { seeAll.push_back(title.PrintBook()) ;}
                }
            }

          else if (sch == "random") { 

               for (const auto& [id, title] : sector) {al++;

                      if (al == nA) { returnJs(title.PrintBook());

                             break;
                      }
                } 
          }

          else if(sch == "delet"){ 

              for (auto it = sector.begin(); it != sector.end(); ) {
                
                    if (it->second.Search() == what) {
                        it = sector.erase(it); 
                    } else {
                        ++it;
                    }
              }
          }


       return 0;

    };

    void returnJs(const std::tuple<T1,T1,T1>*ptr_t)
     {        
          const auto& title = std::get<0>(*ptr_t);
          const auto& author = std::get<1>(*ptr_t);
          const auto& text = std::get<2>(*ptr_t);

          if(js_callback_allT != nullptr)
           {
                js_callback_allT(title.c_str(),author.c_str(),text.c_str());
            }
    }

    void returnJs(int id, const T1& t){

            if(js_callback_T != nullptr)
              {
                 js_callback_T(t.c_str(),id);
              }
    }

    void SeeText(T1 t){ 

       if(!sector_f.empty()){ bool TorF = true;

               for (const auto& [id, title] : sector_f) {

                   if(title.Search() == t){ TorF = false;

                     js_callback_noT(2);

                        break;
                    }
                }

            if(TorF){js_callback_noT(4);}
        }
    }

    void SeeText(const T2 condicao, T2 id){ 

            if(not sector_f.empty()){

                    if(condicao == 1){ returnJs(sector_f[id].PrintBook() );
                     } 

                    else if(condicao == 2){

                             for(const auto& [id, title] : sector_f){ 

                                  returnJs(id,title.Search());
                              };
                        }

                    else if(condicao == 3){ 
                                sector_f.erase(id);   

                               js_callback_noT(3); 
                      }
            }

          else{ js_callback_noT(1); }; 
      }

    void SeeText(const T2 condicao){

           if(condicao == 6 ){ 

                 if(not Fifo.empty()){ returnJs(Fifo.front().PrintBook()); }

                      else{js_callback_noT(1);};
            }

          else if(condicao == 7){

                 if(not Lifo.empty()){returnJs(Lifo.top().PrintBook());}

                      else{js_callback_noT(1);}; 
           }
    }

    void SeeText(const T2 condicao, const T1& sch,const T1& what, const T2 nA)noexcept{  

                                        
                switch(condicao)
                  { 
                     case 0:Sectors(sector_a,sch,what,nA) ;
                             break;
                     case 1:Sectors(sector_b,sch,what,nA);
                             break;
                     case 2:Sectors(sector_c,sch,what,nA);
                             break;
                     case 3:Sectors(sector_d,sch,what,nA);
                             break;
                     case 4:Sectors(sector_e,sch,what,nA);
                             break;
                     case 5:Sectors(sector_f,sch,what,nA);
                             break;
                  };
        }; 
  };


 template<typename T>
   class V {public:
       
      int idc,nAleatorio;
      size_t N;
      double cAleatorio;
      std::string sch{"NULL"};
    

     void randomText(library<std::string,int>* l)
     {
         double soma = 0.0;
         std::random_device rd;
         std::mt19937 motor(rd());
         std::uniform_real_distribution<double> D1(0.0,1.0);
         cAleatorio = D1(motor);
         std::vector<double> pesos ={0.15,0.15,0.18,0.15,0.15,0.22};

         std::ranges::for_each(pesos,[&soma](double p){ soma+=p; });

         auto Acumulado = pesos | std::views::transform([&soma](double p){return p/soma;});
         
         for(size_t A = 0; A<Acumulado.size(); A++)
          {
            if(cAleatorio < Acumulado[A]){ idc=A; };
          };  

         switch(idc){ case 0:N = l[0].sector_a.size();break;
                      case 1:N = l[0].sector_b.size();break;
                      case 2:N = l[0].sector_c.size();break;
                      case 3:N = l[0].sector_d.size();break;
                      case 4:N = l[0].sector_e.size();break;
                      case 5:N = l[0].sector_f.size();break;
                    };

           std::uniform_int_distribution<int> D2(0,N);
           nAleatorio = D2(motor);
           sch = "random";
           l[0].SeeText(idc,sch,"NULL",nAleatorio);
      };
  };
}
