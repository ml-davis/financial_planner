const globalBackgroundColors = [
  'rgba( 30, 144, 255, 0.5)',
  'rgba( 75,  40, 150, 0.5)',
  'rgba(255,  97,   3, 0.5)',
  'rgba(165,  42,  42, 0.5)',
  'rgba(  0, 120,   0, 0.5)',
  'rgba(152, 245, 255, 0.5)',
  'rgba(245,   0, 170, 0.5)',
  'rgba( 10,  50, 140, 0.5)',
  'rgba(  0, 175, 175, 0.5)',
  'rgba(125,  22,  82, 0.5)',
  'rgba(  0, 195,   0, 0.5)',
  'rgba(200, 200,   0, 0.5)',
  'rgba(175, 175, 175, 0.5)',
  'rgba(185,   0,   0, 0.5)',
  'rgba(255, 255, 255, 0.5)',
];

const globalBorderColors = [
  'rgba( 30, 144, 255, 1.0)',
  'rgba( 75,   0, 130, 1.0)',
  'rgba(255,  97,   3, 1.0)',
  'rgba(165,  42,  42, 1.0)',
  'rgba(  0, 120,   0, 1.0)',
  'rgba(152, 245, 255, 1.0)',
  'rgba(245,   0, 170, 1.0)',
  'rgba( 10,  50, 140, 1.0)',
  'rgba(  0, 175, 175, 1.0)',
  'rgba(125,  22,  82, 1.0)',
  'rgba(  0, 195,   0, 1.0)',
  'rgba(175, 175,   0, 1.0)',
  'rgba(175, 175, 175, 1.0)',
  'rgba(185,   0,   0, 1.0)',
  'rgba(255, 255, 255, 1.0)',
];

function loadChart(label, map, type) {
  const ctx = document.getElementById("myChart").getContext('2d');

  let labelArray = new Array();
  let dataArray = new Array();
  let backgroundColors = new Array();
  let borderColors = new Array();

  let index = 0;
  for (const [label, amount] of map) {
    labelArray.push(label);
    dataArray.push(amount);
    backgroundColors.push(globalBackgroundColors[index]);
    borderColors.push(globalBorderColors[index]);
    index = (index + 1) % globalBackgroundColors.length;
  }

  const myChart = new Chart(ctx, {
    type: type,
    data: {
      labels: labelArray,
      datasets: [{
        label: label,
        data: dataArray,
        backgroundColor: backgroundColors,
        borderColor: borderColors,
        borderWidth: 1
      }]
    },
    options: {
      responsive: false,
      legend: {
        labels: {
          fontColor: '#DADADA'
        }
      },
      scales: {
        xAxes: [{
          gridLines: {
            color: '#3C3C3C'
          },
          ticks: {
            fontColor: '#DADADA'
          }
        }],
        yAxes: [{
          gridLines: {
            color: '#3C3C3C'
          },
          ticks: {
            fontColor: '#DADADA',
            beginAtZero:true
          }
        }]
      }
    }
  });
}
