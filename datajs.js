const toggleBtn = document.querySelector('.navbar__togglBtn');
const menu = document.querySelector('.navbar__menu');
const items = document.querySelector('.navbar__items');


toggleBtn.addEventListener('click', () =>{
    menu.classList.toggle('active');
    items.classList.toggle('active');
});

 function openModal() {
    var modal = document.getElementById('myModal');
    modal.style.display = 'flex';
}

function closeModal() {
    var modal = document.getElementById('myModal');
    modal.style.display = 'none';
}

window.onclick = function (event) {
    var modal = document.getElementById('myModal');
    if (event.target === modal) {
        modal.style.display = 'none';
    }
};



/* 가위 바위 보 */
let imageCoordinate = '0';
const dictionary = {
    바위: '0',
    가위: '-200px',
    보: '-390px'
};

function computerPick(imageCoordinate) {
    return Object.entries(dictionary).find(function (v) {
        return v[1] === imageCoordinate;
    })[0];
}

let interval;

function intervalMaker() {
    interval = setInterval(function () {
        if (imageCoordinate === dictionary.바위) {
            imageCoordinate = dictionary.가위
        } else if (imageCoordinate === dictionary.가위) {
            imageCoordinate = dictionary.보;
        } else {
            imageCoordinate = dictionary.바위;
        }
        document.querySelector("#computer").style.background =
            'url(/game.jpg) ' + imageCoordinate + ' 0';
    }, 100);
}

intervalMaker();

const score = {
    가위: 1,
    바위: 0,
    보: -1
};

const result = document.getElementById('result');
const init = document.getElementById('init');
let playTime = 0;
let winNumber = 0;
let loseNumber = 0;
let drawNumber = 0;

document.querySelectorAll('.btn').forEach(function (btn) {
    btn.addEventListener('click', function () {
        clearInterval(interval);
        intervalMaker();
        playTime++;
        init.style.display = 'inline-block';
        const myPick = this.textContent;
        const myScore = score[myPick];
        const computerScore = score[computerPick(imageCoordinate)];
        const scoreGap = myScore - computerScore;
        if (scoreGap === 0) {
            alert('비겼다 !');
            drawNumber++;
        } else if ([-1, 2].includes(scoreGap)) {
            alert('이겼다 !');
            winNumber++;
        } else {
            alert('졌다 !');
            loseNumber++;
        }
        result.innerHTML = "플레이 횟수 = " + playTime + " 게임" + "<br>" + "<br>" +
            winNumber + " 승 " + loseNumber + " 패 " + drawNumber + " 무";
    });
});

function initRecord() {
    playTime = 0;
    winNumber = 0;
    loseNumber = 0;
    drawNumber = 0;
    result.innerHTML = "플레이 횟수 = " + playTime + " 게임" + "<br>" + "<br>" +
        winNumber + " 승 " + loseNumber + " 패 " + drawNumber + " 무";
}

init.addEventListener('click', initRecord);


/* -=========== 스크롤 바  ==============-*/


document.querySelectorAll(".js-horizontal-scroll").forEach(el => {
    el.addEventListener("wheel", e => {
      const atLeftEnd = (el.scrollLeft === 0);
      
      const atRightEnd = (el.scrollLeft + el.offsetWidth >= el.scrollWidth);
  
      // 휠 이벤트가 위로 가는 것인지 아래로 가는 것인지 확인
      const scrollingUp = (e.deltaY < 0);
      const scrollingDown = (e.deltaY > 0);
  
      if ((atLeftEnd && scrollingUp) || (atRightEnd && scrollingDown)) {
        return;
      }

      e.preventDefault();
      el.scrollLeft += e.deltaY * 2;
    })
  });