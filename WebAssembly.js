Module.onRuntimeInitialized = () => { 

  function MyUTF8ToString(ptr) {
     const bytes = []
     let i = ptr
     while (Module.HEAPU8[i] !== 0) {
       bytes.push(Module.HEAPU8[i])
       i++
      }
    return new TextDecoder().decode(new Uint8Array(bytes))
  }

  /*const TitleT = Module.ccall("retornT","number")
  const TextT = Module.ccall("returnTx","number")
  const AuthorA = Module.ccall("returnA","number")
  const titleTT = MyUTF8ToString(TitleT)
  const textTT = MyUTF8ToString(TextT)
  const authorAA = MyUTF8ToString(AuthorA)
     console.log("Randon ",textTT)*/
  let idc = 0
  let t
  let tx
  let ath
  let whatDo
  let title_T
  let id_delet
  let fvrt = 1

  const random = document.getElementById("random")

     random.onclick = function(){ Module.ccall("random_txt",null,["number"],[callbackForCpp_null] )}


  const radios = document.querySelectorAll('input[name="category"]');

   radios.forEach(radio => {
        radio.addEventListener("change", function() {

                 whatDo = parseInt(this.value)

                search()
         })
   })

 const lupa = document.querySelector("span");
   lupa.addEventListener("click", function(){

       title_T = document.getElementById("search_t").value
       document.getElementById("search_t").value = ""
       whatDo = 8
       search()
     }
   )

  
  function search(){ 

     const encoder = new TextEncoder()
     const title_tt = encoder.encode(title_T)
     const Title = Module._malloc(title_tt.length+1)
     Module.HEAPU8.set(title_tt,Title)
     Module.HEAPU8[Title + title_tt.length] = 0
 
     Module.ccall("search",null,["number","number","number","number","number"],[whatDo,Title,callbackForCpp,callbackForCpp_null,otherCallback])
     
   }


  const btn_x = document.getElementById("ex")

   btn_x.onclick = function(){ 
      
      if(whatDo != 2){

               whatDo = 10
               title_T = t
               search() 
      }
    else{  Module.ccall("especific_t",null,["number","number","number"],[id_delet,whatDo,1]) }
   }


   const otherCallback = Module.addFunction( function(ptrTitle2,ptrAuthor2,ptrText2)

           {       t = MyUTF8ToString(ptrTitle2)
                   tx = MyUTF8ToString(ptrText2)
                   ath = MyUTF8ToString(ptrAuthor2)

                   document.getElementById("t").innerHTML =  t
                   document.getElementById("tx").innerHTML = tx    
                   document.getElementById("athr").innerHTML = ath

                  if(whatDo == 6 || whatDo == 7){  document.getElementById("ex").style.display = "none"; }

                   const btn_f = document.getElementById("fvrt")

                   btn_f.onclick = function(){ 

                        whatDo = 1
                        title_T = t

                        if(fvrt == 1){ register(5,t,tx,ath) 
                                       fvrt = 0 
                         }
                        else{ search() }
                     }
                  
                   openWindons(2)

           },'viii'
      )

   const callbackForCpp = Module.addFunction( function(ptrTitle,ptr_id) { 

                           const title = MyUTF8ToString(ptrTitle)

                           const btn = document.createElement("button")
                                 btn.textContent = title
                                 btn.dataset.id = ptr_id
                                 btn.className = 'textList'
            
                                 btn.addEventListener("click",()=>{  id_delet = btn.dataset.id

                                     Module.ccall("especific_t",null,["number","number","number"],[btn.dataset.id,whatDo,0])

                                  })
                           document.getElementById("T").appendChild(btn)
                           openWindons(1)
                   
            },'vii'
      )

   const callbackForCpp_null = Module.addFunction( function(i){ 

                         if(i == 1){document.getElementById("fvrt_t").innerHTML = "Nenhum Texto Encontrado ⚠️ "}

                         else if(i == 3){ document.getElementById("fvrt_t").innerHTML = "Texto excluido com sucesso ⚠️" }

                         else if(i == 4){ register(5,t,tx,ath); }

                         else if(i == 2){document.getElementById("fvrt_t").innerHTML = "Ja existe um texto com o mesmo título adicionado ao favoritos. O conteudo de ambos podem ser iguais. Deseja continuar ?"
                               
                                const btn_S = document.createElement("button")
                                btn_S.textContent = "Sim"
                                btn_S.className = 'btn_opc'
                                btn_S.id = "btn_S"

                                const btn_N = document.createElement("button")
                                btn_N.textContent = "Não"
                                btn_N.className = "btn_opc"
                                btn_N.id = "btn_N"

                                document.getElementById("NTC").appendChild(btn_S)
                                document.getElementById("NTC").appendChild(btn_N)

                                 const btn_SS = document.getElementById("btn_S")

                                    btn_SS.onclick = function(){  closeWindows(3); register(5,t,tx,ath) }

                                const btn_NN = document.getElementById("btn_N")

                                    btn_NN.onclick = function(){ closeWindows(3); 
 
                                    }

                           }
                        
                          openWindons(3)

       },'vi'
     )



   document.getElementById("register").addEventListener("click",function(){

               let t_t = document.getElementById("title").value
               let t_x = document.getElementById("text").value
               let a_th = document.getElementById("author").value

                register(idc,t_t,t_x,a_th)

                idc += 1

                if(idc == 5){idc = 0}
           }
   )

   function register(opc,title_t,text_t,author_a){ 
   
   
     const encoder = new TextEncoder()
     
     const title_tt = encoder.encode(title_t)
     const text_tx = encoder.encode(text_t)
     const author_aa = encoder.encode(author_a)

     const title = Module._malloc(title_tt.length+1)
     const text = Module._malloc(text_tx.length+1)
     const author = Module._malloc(author_aa.length+1)

     Module.HEAPU8.set(title_tt,title)
     Module.HEAPU8.set(text_tx,text)
     Module.HEAPU8.set(author_aa,author)

     Module.HEAPU8[title + title_tt.length] = 0
     Module.HEAPU8[text + text_tx.length] = 0
     Module.HEAPU8[author + author_aa.length] = 0


     Module.ccall("Register",null,["number","number","number","number"],[title,text,author,opc])

     document.getElementById("title").value = ''
     document.getElementById("text").value = ''
     document.getElementById("author").value = ''

     if(opc == 5){  document.getElementById("fvrt_t").innerHTML = "Texto salvo nos favoritos ⭐️"
                    openWindons(3) 
      }
     else{ document.getElementById("fvrt_t").innerHTML = "Texto Salvo com Sucesso ✅"
           openWindons(3)
      }
      
  }
}

 
 function openWindons(args){

        if(args == 1){document.getElementById("Windons_btn").style.display = "flex"}

        if(args == 2){document.getElementById("Windons_text").style.display = "flex" }

        if(args == 3){document.getElementById("Windons_F").style.display = "flex" }        
   }

function closeWindows(args) {
    const windows = {
        1: "Windons_btn",
        2: "Windons_text",
        3: "Windons_F"
    };

    const targetId = windows[args];
    if (targetId) {
        document.getElementById(targetId).style.display = "none";
    }


    document.querySelectorAll('input[name="category"]').forEach(radio => radio.checked = false);

    
    if (args === 1) {
        document.querySelectorAll('#T .textList').forEach(btn => btn.remove());
        Module.ccall("clear_vetor", null);
    } 

   else if(args == 2){ document.getElementById("ex").style.display = "flex";  }

    else if (args === 3) {
        
         Module.ccall("clear_vetor", null);

        const els = document.getElementsByClassName("btn_opc");
        Array.from(els).forEach(el => el.remove());

        document.querySelectorAll('#T .textList').forEach(btn => btn.remove());
        document.getElementById("Windons_btn").style.display = "none"
        document.getElementById("Windons_text").style.display = "none"
    }
}

function close_click_away(event, args) {
    
    if (event.target === event.currentTarget) { 
        closeWindows(args); 
    }
}

