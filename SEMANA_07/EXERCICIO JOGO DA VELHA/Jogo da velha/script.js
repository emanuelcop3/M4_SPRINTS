//Url com o IP definido
let url = "http://10.254.17.241/";

//Mostarnado o jogador que começa
const currentPlayer = document.querySelector(".currentPlayer");
// selecionando a posição
let selected;

// Movimentações
let positions = [
    [1,2,3],
    [4,5,6],
    [7,8,9],
    [1,4,7],
    [2,5,8],
    [3,6,9],
    [1,5,9],
    [3,5,7],
];


//Jogador que  começa com X
let player = "X";

//Função de iniciar o game
function init() {

    //Inputs (X ou O) que  é armazenada no array
    selected = [];

    
   
    if (selected.length === 0){
      document.querySelectorAll(".game button").forEach((item) => {
      item.style.backgroundColor = "white";
    });
    }

    // Clicando para chamar a função
    document.querySelectorAll(".game button").forEach((item) => {
        item.innerHTML = "";
        item.addEventListener("click", newMove);
    });


    //Requisição é enviada pelo ajax
    if (player == "X"){
      $.ajax({
        url: url + "turnX",
      })
    }
    else if (player == "O"){
      $.ajax({
        url: url + "turnO",
      })
    }

}

//Iniciando a função
init();


//Função criada para movimento
function newMove(e) {
    //Atributo de cada botão
    const index = e.target.getAttribute("data-i");
    e.target.innerHTML = player;
    //Remove o evento para clicar no botão da função newmove
    e.target.removeEventListener("click", newMove);
    //Armazena no array cada posição
    selected[index] = player;

    //Troca de jogadores depois da função palyer
    setTimeout(() => {
        check();
    }, [100]);
    //Mudanças de jogadores 
    player = player === "X" ? "O" : "X";
    currentPlayer.innerHTML = `É a vez do ${player} jogar!!`;

    //Definição de css e estilos
    button = e.target;
    if (button.innerHTML === "O"){
      button.style.color = "red";
      button.style.backgroundColor = "#eff4f0"
    }
    else if (button.innerHTML === "X"){
      button.style.color = "#07a431";
      button.style.backgroundColor = "#eff4f0";
    }
  
    //Ajax que manda requisições
    if (player == "X"){
      $.ajax({
        url: url + "turnX",
      })
    }
    else if (player == "O"){
      $.ajax({
        url: url + "turnO",
      })
    }

};

// Processo de checagem
function check() {
    //Último player a jogar
    let playerLastMove = player === "X" ? "O" : "X";

  // mapeando o índex
    const items = selected
        .map((item, i) => [item, i])
        .filter((item) => item[0] === playerLastMove)
        .map((item) => item[1]);

    
    //percorre as posições 
    
    for (pos of positions) {
        if (pos.every((item) => items.includes(item))) {
            if (playerLastMove ){
              winX();
              alert( playerLastMove );
            }
            else if ((playerLastMove )){
              winO();
              alert(playerLastMove);
            }
            
            init();
            return;
        }
    }

    
}


//Requisições do ajax para quem ganha 
function winX(){
     $.ajax({
        url: url + "winX",
    })
}

//Requisições do ajax para quem ganha 
function winO(){
  $.ajax({
     url: url + "winO",
 })
}

