<?php
// $Id$

/**
 * @file
 *   Theme callbacks and preprocess functions.
 */

/**
 * Theme callback to return a chargify state
 */
function theme_chargify_subscription_state($state = '') {
  if ($label = chargify_subscription_state($state)) {
    return "<div class='chargify-state $state'>$label</div>";
  }
}

/**
 * Theme callback to return a product price.
 */
function theme_chargify_product_price($product) {
  if (is_object($product)) {
    $denom = '<span class="denom">$</span>';
    $price = $product->getPriceInDollars();
    $divider = t('per');
    $interval = $product->getIntervalUnit();

    $output = "<div class='chargify-product-price'>\n";
    $output .= "<span class='price'>{$denom}{$price}</span>\n";
    $output .= "&nbsp;<span class='divider'>$divider</span>\n";
    $output .= "&nbsp;<span class='interval'>$interval.</span>\n";
    $output .= "</div>";

    return $output;
  }
}