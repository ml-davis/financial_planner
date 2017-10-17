const webpack = require('webpack');

module.exports = {
  context: __dirname + "/src",
  devtool: "inline-sourcemap",
  entry: "./js/client.js",
  module: {
    loaders: [
      {
        test: /\.js?$/,
        exclude: /(node_modules|bower_components)/,
        loader: 'babel-loader',
        query: {
          presets: ['react', 'es2015', 'stage-0'],
          plugins: ['react-html-attrs', 'transform-class-properties', 'transform-decorators-legacy']
        }
      }
    ]
  },
  output: {
    path: __dirname + "/src",
    filename: "client.min.js"
  },
  plugins: []
};
