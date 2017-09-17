const globalBackgroundColors = [
  'rgba(192,  57,  43, 0.2)',
  'rgba(175, 122, 197, 0.2)',
  'rgba( 41, 128, 185, 0.2)',
  'rgba( 26, 188, 156, 0.2)',
  'rgba(241, 196,  15, 0.2)',
  'rgba(211,  84,   0, 0.2)',
  'rgba(189, 195, 199, 0.2)',
  'rgba( 52,  73,  94, 0.2)',
  'rgba(231,  76,  60, 0.2)',
  'rgba(142,  68, 173, 0.2)',
  'rgba( 52, 152, 219, 0.2)',
  'rgba( 39, 174,  96, 0.2)',
  'rgba(243, 156,  18, 0.2)',
  'rgba( 33,  47,  61, 0.2)',
  'rgba(120,  66,  18, 0.2)',
  'rgba( 14,  98,  81, 0.2)'
];

const globalBorderColors = [
  'rgba(192,  57,  43, 1.0)',
  'rgba(175, 122, 197, 1.0)',
  'rgba( 41, 128, 185, 1.0)',
  'rgba( 26, 188, 156, 1.0)',
  'rgba(241, 196,  15, 1.0)',
  'rgba(211,  84,   0, 1.0)',
  'rgba(189, 195, 199, 1.0)',
  'rgba( 52,  73,  94, 1.0)',
  'rgba(231,  76,  60, 1.0)',
  'rgba(142,  68, 173, 1.0)',
  'rgba( 52, 152, 219, 1.0)',
  'rgba( 39, 174,  96, 1.0)',
  'rgba(243, 156,  18, 1.0)',
  'rgba( 33,  47,  61, 1.0)',
  'rgba(120,  66,  18, 1.0)',
  'rgba( 14,  98,  81, 1.0)'
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
    type: type, // many other types: bar, line, pie, etc
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
      scales: {
        yAxes: [{
          ticks: {
            beginAtZero:true
          }
        }]
      }
    }
  });
}
